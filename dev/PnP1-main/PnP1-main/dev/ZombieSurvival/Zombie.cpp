#include "Zombie.h"
#include <iostream>

Zombie::Zombie()
{
    health = 50;
    attackPower = 10;
    zombieType = "Normal";
}
Zombie::Zombie(int startingHealth, int startingAttackPower, std::string type)
{
    health = startingHealth;
    attackPower = startingAttackPower;
    zombieType = type;
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
int Zombie::getAttackPower() const
{
    return attackPower;
}
std::string Zombie::getZombieType() const
{
	return zombieType;
}
