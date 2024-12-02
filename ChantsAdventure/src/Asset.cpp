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
        return  _isOffensive && _isDefensive ? true : false;
    }

}