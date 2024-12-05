#include <Combatant.hpp>
#include <time.h>
#include <iostream>
using namespace std;

namespace chants
{
    /**
     * @brief Construct a new Combatant object.
     * 
     * @param name The name of the combatant.
     * @param health The initial health of the combatant.
     * @param fightCoefficient The fight coefficient affecting combat performance.
     */
    Combatant::Combatant(string name, int health, int fightCoefficient)
    {
        _name = name;
        _health = health;
        _fightCoefficient = fightCoefficient;
    }

    /**
     * @brief Get the name of the combatant.
     * 
     * @return string The name of the combatant.
     */
    string Combatant::GetName()
    {
        return _name;
    }

    /**
     * @brief Get the current health of the combatant.
     * 
     * @return int The current health of the combatant.
     */
    int Combatant::GetHealth()
    {
        return _health;
    }
    
    /// @brief combatant rolls dice
    /// @return random value 1-6 (we can change this (as an argument parameter) to simulate higher order dice (D12 D20) if you guys want )
    int Combatant::rollDice(){
        srand(time(nullptr));
        // if you guys want to prompt the player to roll the dice or not but if we wanted we can uncomment this line
        // cout << "Would you like to roll a dice> [Y/N]"<<endl;
        cout <<"Rolling dice..."<< endl;
        int diceRoll = (rand()%12)+1;
        cout << "You rolled a " << diceRoll << "!"<< endl;
        return diceRoll;
    }

    /// @brief combatant fight will return a dice roll, the player and combatant classes use this to attack the player
    /// @return
    int Combatant::Fight()
    {
        return(rollDice());
    }

    /**
     * @brief Apply damage to the current combatant.
     * 
     * @param damage The amount of damage taken.
     */
    void Combatant::takeDamage(int damage){
        cout << GetName() << " took " << to_string(damage) << " damage!\n";
        _health -= damage;
    }
}
