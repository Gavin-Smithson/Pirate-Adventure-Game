#include <Asset.hpp>

namespace chants
{
    Asset::Asset(string name, string message, int value, bool isOffensive, bool isDefensive)
    {
        _name = name;
        _message = message;
        _value = value;
        _isOffensive = isOffensive;
        _isDefensive = isDefensive;
        hasBeenUsed = false;
    }

    string Asset::GetName()
    {
        return _name;
    }

    string Asset::GetMessage()
    {
        return _message;
    }

    int Asset::GetValue()
    {
        return _value;
    }
#include <Asset.hpp>

namespace chants
{
    /**
     * @brief Construct a new Asset object.
     * 
     * @param name The name of the asset.
     * @param message A message associated with the asset.
     * @param value The value or potency of the asset.
     * @param isOffensive Indicates if the asset is offensive in nature.
     * @param isDefensive Indicates if the asset is defensive in nature.
     */
    Asset::Asset(string name, string message, int value, bool isOffensive, bool isDefensive)
    {
        _name = name;
        _message = message;
        _value = value;
        _isOffensive = isOffensive;
        _isDefensive = isDefensive;
        hasBeenUsed = false;
    }

    /**
     * @brief Get the name of the asset.
     * 
     * @return string The name of the asset.
     */
    string Asset::GetName()
    {
        return _name;
    }

    /**
     * @brief Get the message associated with the asset.
     * 
     * @return string The message.
     */
    string Asset::GetMessage()
    {
        return _message;
    }

    /**
     * @brief Get the value or potency of the asset.
     * 
     * @return int The value of the asset.
     */
    int Asset::GetValue()
    {
        return _value;
    }

    /**
     * @brief Check if the asset is offensive.
     * 
     * @return true If the asset is offensive.
     * @return false If the asset is not offensive.
     */
    bool Asset::isOffensive()
    {
        return _isOffensive;
    }

    /**
     * @brief Check if the asset is defensive.
     * 
     * @return true If the asset is defensive.
     * @return false If the asset is not defensive.
     */
    bool Asset::isDefensive()
    {
        return _isDefensive;
    }

    /**
     * @brief Check if the asset is healing (neither offensive nor defensive).
     * 
     * @return true If the asset is healing.
     * @return false If the asset is not healing.
     */
    bool Asset::isHealing() 
    {
        return !_isOffensive && !_isDefensive ? true : false;
    }
}

    bool Asset::isOffensive()
    {
        return _isOffensive;
    }
    bool Asset::isDefensive()
    {
        return _isDefensive;
    }

    bool Asset::isHealing() 
    {
        return  !_isOffensive && !_isDefensive ? true : false;
    }

}