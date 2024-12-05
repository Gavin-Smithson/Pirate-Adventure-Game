#include <Monster.hpp>

namespace chants
{
    /**
     * @brief Construct a new Monster object.
     * 
     * @param name The name of the monster.
     * @param health The initial health of the monster.
     * @param fightCoefficient The fight coefficient affecting the monster's combat performance.
     */
    Monster::Monster(string name, int health, int fightCoefficient) : Combatant(name, health, fightCoefficient)
    {
        name = _name;
        health = _health;
        fightCoefficient = _fightCoefficient;
    }

    /**
     * @brief Perform a monster attack.
     * 
     * @details Rolls a dice to determine the monster's attack value and adds the fight coefficient.
     * If the dice roll plus the fight coefficient is less than zero, the attack value is set to zero.
     * 
     * @return int The resulting attack value.
     */
    int Monster::monsterAttack(){
        int diceRoll = rollDice();
        // return the diceroll + fightCoefficient, if diceroll + fightCoefficient is less than zero, return 0
        return max(0, diceRoll) + _fightCoefficient;
    }
}
