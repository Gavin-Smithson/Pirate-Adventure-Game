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
    /**
     * @brief Adds an asset to the player's asset vector
     * 
     * @note Asset should ONLY be a healing potion
     * @param asset is the asset being added
     */
    void Player::AddAsset(Asset asset)
    {
        _assets.push_back(asset);
    }

    /**
     * @brief Totals the asset value of the player
     * 
     * @return int is the total asset value
     */
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

    /**
     * @brief Helper method to remove an asset for a given index
     * 
     * @param index is the desired index of the asset you want to remove
     */
    void Player::RemoveAsset(int index)
    {
        _assets.erase(_assets.begin() + index);
    }
    /**
     * @brief Displays the current equipment to the player
     * 
     */
    void Player::DisplayEquipment()
    {
        cout << "Weapon: " << _Equipment[0].GetName() << endl;
        cout << _Equipment[0].GetMessage() << endl;

        cout << "Armor: " << _Equipment[1].GetName() << endl;
        cout << _Equipment[1].GetMessage() << endl;
    }

    /**
     * @brief Takes the last added potion and heals the player to their maximum health
     * 
     */
    void  Player::usePotion(){
        bool foundHealthPotion = false;
        for (Asset asset : _assets){
            // Check to see if current asset is a healing potion
            if (asset.isHealing()) {
                foundHealthPotion= true;

                // Set the player to full health
                _health = maxHealth;

                // Erase the last health potion
                _assets.pop_back();
            }
        }
        if (!foundHealthPotion){
            cout << "No health potions in inventory"<< endl;
        }

    }
    
    /**
     * @brief Generates a damage value based off of a random dice roll
     * 
     * @return int The damage the player did in the attack
     */
    int Player::playerAttack(){
        int diceRoll = rollDice();
        return diceRoll + GetAttack() + _fightCoefficient;
    }

    /**
     * @brief Used to apply damage to the player
     * 
     * @param damage is the value of damage the player should take
     */
    void Player::takeDamage(int damage) {
        int netDamage = damage - GetDefense();

        if (netDamage <= 0) {
            cout <<"No damage taken" <<endl;
            return;
        }
        
        _health -=  netDamage;

        // Ensure health doesn't go below zero
        if (_health < 0) {
            _health = 0;
        }
    }

    /**
     * @brief This method will handle equiping any asset
     * 
     * @param asset This is the asset the player is attempting to equip
     */
    void Player::TakeAsset(Asset asset) {
        // Call the equip asset method and get it's sucess bool
        bool sucessEquipAsset = EquipAsset(asset);

        // If unscuessful, the item is a healing potion. So add it to the assets vector
        if (!sucessEquipAsset) {
            Player::AddAsset(asset);
        }
    }

    /**
     * @brief Helper method to equip a given asset
     * 
     * @param asset Given asset you want to equip
     */
    bool Player::EquipAsset(Asset asset) {
        int assetIndex = asset.isOffensive() ? 0 : asset.isDefensive() ? 1 : -1; 

        // Exit clause if the asset is an healing item
        if (assetIndex == -1) {
            printf("Asset is a healing item and cannot be equiped.");
            return false;
        }

        // Equip the asset and display it to the player
        cout << "You equipped the \"" << asset.GetName() << "\"" << endl;
        _Equipment[assetIndex] = asset;

        return true;
    }

    int Player::GetNumPotions()
    {
        int numPotions = 0;
        for (Asset asset : _assets)
        {
            numPotions += 1;
        }

        return numPotions;
    }
}