#include "Zombie.h"
#include <iostream>

Zombie::Zombie()
{
    health = 50;
    attackPower = 10;
}

void Zombie::attack()
{
    std::cout << "The zombie attacks!\n";
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