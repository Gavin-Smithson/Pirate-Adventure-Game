#include <Combatant.hpp>
#include <time.h>
#include <iostream>
using namespace std;

namespace chants
{
    Combatant::Combatant(string name, int health, int fightCoefficient)
    {
        _name = name;
        _health = health;
        _fightCoefficient = fightCoefficient;
    }

    string Combatant::GetName()
    {
        return _name;
    }

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
        int diceRoll = (rand()%6)+1;
        cout << "You rolled a " << diceRoll << "!"<< endl;
        return diceRoll;


    }

    /// @brief combatant fight will return a dice roll, the player and combatant classes use this to attack the player
    /// @return
    int Combatant::Fight()
    {
        return(rollDice());
    }
    /// @brief take damage for the current combatant
    /// @param damage - the amount of damage taken
    void Combatant::takeDamage(int damage){
        _health -= damage;

    }
}
