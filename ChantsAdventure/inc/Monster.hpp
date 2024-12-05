#pragma once

#include <string>
#include <Combatant.hpp>

using namespace std;

namespace chants
{
    /**
     * @brief The Monster class represents a monster in the game world.
     * 
     * @details Inherits from Combatant and provides functionality specific to monsters,
     * such as performing attacks.
     */
    class Monster : public Combatant
    {
    public:
        /**
         * @brief Construct a new Monster object.
         * 
         * @param name The name of the monster.
         * @param health The initial health of the monster.
         * @param fightCoefficient The fight coefficient affecting the monster's combat performance.
         */
        Monster(string name, int health, int fightCoefficient);

        /**
         * @brief Perform an attack as the monster.
         * 
         * @details Rolls a dice to determine the monster's attack value. Additional logic
         * may be applied based on the fight coefficient.
         * 
         * @return int The attack value resulting from the dice roll.
         */
        int monsterAttack();
    };
}
