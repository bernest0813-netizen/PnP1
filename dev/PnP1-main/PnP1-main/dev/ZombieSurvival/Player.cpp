#include "Player.h"
#include <iostream>
#include <random>

Player::Player()
{
	health = 100;
	attackPower = 20;
	score = 0;
}

int Player::attack()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> chance(1, 100);

	int damage = attackPower;

	if (chance(gen) <= 20)
	{
		damage *= 2;
		std::cout << "\nCRITICAL HIT!\n";
	}
	std::cout << "You attack the zombie for " << damage << " damage.\n";

	return damage;
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
void Player::addScore(int points)
{
	score += points;
}
void Player::rewardHealth()
{
	health += 15;

	if (health > 100)
	{
		health = 100;
	}
	std::cout << "Wave Survival Bonus! +15 Health!\n";
}
