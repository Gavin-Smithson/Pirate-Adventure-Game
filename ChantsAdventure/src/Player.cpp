#include <Player.hpp>
#include <iostream>

namespace chants
{

    Player::Player(string name, int health, int fightCoefficient) : Combatant(name, health, fightCoefficient)
    {
        //An integer to track the maximum health value of the player
        //Prevents health overflow via healing items
        maxHealth = _health;
        
        //Starting assets for the player
        Asset DefaultWeapon("Knife", "A small but sturdy blade.", 1, true);
        Asset DefaultArmor("Pirate's Clothes", "The clothes of a former life.", 1, false, true);
        _Equipment.push_back(DefaultWeapon);
        _Equipment.push_back(DefaultArmor);
    }

    void Player::AddAsset(Asset asset)
    {
        _assets.push_back(asset);
    }

    int Player::GetTotalAssetValue()
    {
        int val = 0;
        for (Asset asset : _assets)
        {
            val += asset.GetValue();
        }
        return val;
    }

    /// @brief Gets the value of the player's equipped weapon
    /// @return int
    int Player::GetAttack()
    {
        return _Equipment[0].GetValue();
    }

    /// @brief Gets the value of the player's equipped armor
    /// @return int
    int Player::GetDefense()
    {
        return _Equipment[1].GetValue();
    }

    void Player::RemoveAsset(int index)
    {
        _assets.erase(_assets.begin() + index);
    }

    void Player::DisplayEquipment()
    {
        cout << "Weapon: " << _Equipment[0].GetName() << endl;
        cout << _Equipment[0].GetMessage() << endl;

        cout << "Armor: " << _Equipment[1].GetName() << endl;
        cout << _Equipment[1].GetMessage() << endl;
    }

    //Function that will use any asset. Usage is determined by the asset's boolean flags.
    void Player::UseAsset(Asset asset)
    {
        //If the asset is a weapon
        if (asset.isOffensive())
        {
            cout << "You equipped the \"" << asset.GetName() << "\"" << endl;
            Asset tempAsset = _Equipment[0];
            _Equipment[0] = asset;
            AddAsset(tempAsset);

        }
        //If the asset is armor
        else if (asset.isDefensive())
        {
            cout << "You equipped the \"" << asset.GetName() << "\"" << endl;
            Asset tempAsset = _Equipment[1];
            _Equipment[1] = asset;
            AddAsset(tempAsset);
        }
        //If the asset is neither, it is a healing item.
        else
        {
            //If the player's health is not full, a healing item can be used
            if (_health < maxHealth)
            {
                _health += asset.GetValue();
                
                //If the healing item added health over the maximum, health is set to the maximum instead
                if (_health > maxHealth)
                {
                    _health == maxHealth;
                }

                //The healing item is flagged as used
                asset.hasBeenUsed = true;
            }

            //If the player's health is already full, a string is outputted and the item is not used
            else
            {
                cout << "Your health is already full.";
            }
        }
    }

    // need to create function to find a potion in the assets vector, then call the useAsset method on it
    void  Player::usePotion(){
        bool foundHealthPotion = false;
        for (Asset asset : _assets){
            // asset is healing potion
            if (asset.isOffensive() == false && asset.isDefensive() == false){
                UseAsset(asset);
                foundHealthPotion= true;
                break;
            }

        }
        if (foundHealthPotion == false){
            cout << " No health potions in inventory"<< endl;
        }

    }

    int Player::playerAttack(){
        int diceRoll = rollDice();
        return diceRoll + GetAttack() + _fightCoefficient;
    }

void Player::takeDamage(int damage) {
    int netDamage = damage - GetDefense();

    if (netDamage <= 0) {
        return;
    }

    _health -= netDamage;

    // Ensure health doesn't go below zero
    if (_health < 0) {
        _health = 0;
    }
}

}