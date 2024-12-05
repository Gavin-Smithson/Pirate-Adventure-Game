#pragma once
#include <string>
using namespace std;

namespace chants
{
    /**
     * @brief The Combatant class serves as a base class for characters involved in combat.
     * 
     * @details This class provides basic functionality for combatants, including rolling dice,
     * fighting, and taking damage. It is designed to be inherited by more specific combatant types.
     */
    class Combatant
    {
    protected:
        string _name; ///< The name of the combatant.
        int _health; ///< The current health of the combatant.
        int _fightCoefficient; ///< The fight coefficient influencing combat effectiveness.

    public:
        /**
         * @brief Roll a dice to determine a random value.
         * 
         * @details Simulates a dice roll, typically used in combat actions.
         * 
         * @return int The result of the dice roll.
         */
        int rollDice();

        /**
         * @brief Construct a new Combatant object.
         * 
         * @param name The name of the combatant.
         * @param health The initial health of the combatant.
         * @param coefficient The fight coefficient affecting combat performance.
         */
        Combatant(string name, int health, int coefficient);

        /**
         * @brief Perform a combat action.
         * 
         * @details Uses a dice roll to determine the result of the combat action.
         * 
         * @return int The result of the combat action.
         */
        int Fight();

        /**
         * @brief Get the name of the combatant.
         * 
         * @return string The name of the combatant.
         */
        string GetName();

        /**
         * @brief Get the current health of the combatant.
         * 
         * @return int The current health value.
         */
        int GetHealth();

        /**
         * @brief Apply damage to the combatant.
         * 
         * @details Reduces the combatant's health by the specified amount of damage.
         * 
         * @param damage The amount of damage to apply.
         */
        virtual void takeDamage(int damage);
    };
}
