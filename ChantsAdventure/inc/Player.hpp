#pragma once

#include <string>
#include <vector>
#include <Asset.hpp>
#include <Combatant.hpp>

using namespace std;

namespace chants
{
    /**
     * @brief The Player class represents a player character in the game.
     * 
     * @details Inherits from Combatant and adds functionality for managing assets,
     * equipment, and specialized player actions such as attacking and using potions.
     */
    class Player : public Combatant
    {
    private:
        vector<Asset> _assets; ///< The list of assets owned by the player.
        vector<Asset> _Equipment; ///< The list of equipped assets.

    public:
        int maxHealth; ///< The maximum health of the player.

        /**
         * @brief Construct a new Player object.
         * 
         * @param name The name of the player.
         * @param health The initial health of the player.
         * @param fightCoefficient The fight coefficient affecting combat performance.
         */
        Player(string name, int health, int fightCoefficient);

        /**
         * @brief Add an asset to the player's inventory.
         * 
         * @param asset The asset to add.
         */
        void AddAsset(Asset asset);

        /**
         * @brief Get the total value of all assets in the player's inventory.
         * 
         * @return int The total value of the player's assets.
         */
        int GetTotalAssetValue();

        /**
         * @brief Calculate the player's attack value based on assets and fight coefficient.
         * 
         * @return int The total attack value.
         */
        int GetAttack();

        /**
         * @brief Calculate the player's defense value based on equipped assets.
         * 
         * @return int The total defense value.
         */
        int GetDefense();

        /**
         * @brief Use an asset from the player's inventory.
         * 
         * @param asset The asset to use.
         */
        void UseAsset(Asset asset);

        /**
         * @brief Remove an asset from the player's inventory by index.
         * 
         * @param index The index of the asset to remove.
         */
        void RemoveAsset(int index);

        /**
         * @brief Add an asset to the player's inventory.
         * 
         * @param asset The asset to add.
         */
        void TakeAsset(Asset asset);

        /**
         * @brief Equip an asset from the player's inventory.
         * 
         * @param asset The asset to equip.
         * @return true If the asset was successfully equipped.
         * @return false If the asset could not be equipped.
         */
        bool EquipAsset(Asset asset);

        /**
         * @brief Display all currently equipped assets.
         */
        void DisplayEquipment();

        /**
         * @brief Perform a player attack, factoring in assets and fight coefficient.
         * 
         * @return int The attack value.
         */
        int playerAttack();

        /**
         * @brief Use a potion to restore health or provide other benefits.
         */
        void usePotion();

        /**
         * @brief Apply damage to the player.
         * 
         * @param damage The amount of damage taken.
         */
        void takeDamage(int damage) override;

        /**
         * @brief Get the number of potions in the player's inventory.
         * 
         * @return int The number of potions.
         */
        int GetNumPotions();
    };
}
