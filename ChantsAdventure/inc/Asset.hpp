#pragma once

#include <string>

using namespace std;

namespace chants
{
    /**
     * @brief The Asset class represents an item or resource that can be used by a player or within the game.
     * 
     * @details Assets can have various properties such as being offensive, defensive, or healing,
     * and they may have a value and associated message.
     */
    class Asset
    {
    private:
        string _name; ///< The name of the asset.
        string _message; ///< A message or description associated with the asset.
        int _value; ///< The value or potency of the asset.
        bool _isOffensive; ///< Indicates if the asset is offensive in nature.
        bool _isDefensive; ///< Indicates if the asset is defensive in nature.

    public:
        bool hasBeenUsed; ///< Tracks whether the asset has already been used.

        /**
         * @brief Construct a new Asset object.
         * 
         * @param name The name of the asset.
         * @param message A descriptive message for the asset.
         * @param value The value or potency of the asset.
         * @param isOffensive Indicates if the asset is offensive. Defaults to false.
         * @param isDefensive Indicates if the asset is defensive. Defaults to false.
         */
        Asset(string name, string message, int value, bool isOffensive = false, bool isDefensive = false);

        /**
         * @brief Get the name of the asset.
         * 
         * @return string The name of the asset.
         */
        string GetName();

        /**
         * @brief Get the message associated with the asset.
         * 
         * @return string The message of the asset.
         */
        string GetMessage();

        /**
         * @brief Get the value of the asset.
         * 
         * @return int The value of the asset.
         */
        int GetValue();

        /**
         * @brief Check if the asset is offensive.
         * 
         * @return true If the asset is offensive.
         * @return false If the asset is not offensive.
         */
        bool isOffensive();

        /**
         * @brief Check if the asset is defensive.
         * 
         * @return true If the asset is defensive.
         * @return false If the asset is not defensive.
         */
        bool isDefensive();

        /**
         * @brief Check if the asset is healing (neither offensive nor defensive).
         * 
         * @return true If the asset is healing.
         * @return false If the asset is not healing.
         */
        bool isHealing();
    };
}
