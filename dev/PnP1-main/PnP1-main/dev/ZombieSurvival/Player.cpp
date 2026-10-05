#include "Player.h"
#include <iostream>

Player::Player()
{
	health = 100;
	attackPower = 20;
	score = 0;
}

int Player::attack()
{
	std::cout << "You attack the zombie for " << attackPower << " damage.\n";
	
	return attackPower;
}

void Player::takeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
	}
}

void Player::heal()
{
	health += 20;
	if (health > 100)
	{
		health = 100;
	}

	std::cout << "You healed for 20 health.\n";
}

int Player::getHealth() const
{
	return health;
}

int Player::getScore() const
{
	return score;
}
