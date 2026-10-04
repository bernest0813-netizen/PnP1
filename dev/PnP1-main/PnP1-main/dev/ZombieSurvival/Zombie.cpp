#include "Zombie.h"
#include <iostream>

Zombie::Zombie()
{
    health = 50;
    attackPower = 10;
}

int Zombie::attack()
{
    std::cout << "The zombie attacks for " << attackPower << " damage!\n";
    
    return attackPower;
}

void Zombie::takeDamage(int damage)
{
    health -= damage;

    if (health < 0)
    {
        health = 0;
    }
}

int Zombie::getHealth() const
{
    return health;
}