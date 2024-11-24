#include <Monster.hpp>

namespace chants
{
    Monster::Monster(string name, int health, int fightCoefficient) : Combatant(name, health, fightCoefficient)
    {
        name = _name;
        health = _health;
        fightCoefficient = _fightCoefficient;
    }

    int Monster::monsterAttack(){
        int diceRoll = rollDice();
        // return the diceroll + fightCoefficient, if diceroll + fightCoefficient is less than zero, return 0
        return (diceRoll + _fightCoefficient < 0) ? 0 : (diceRoll + _fightCoefficient);

    }
    
}