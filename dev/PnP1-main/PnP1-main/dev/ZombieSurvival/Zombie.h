#pragma once
#include <string>


class Zombie
{
private:
	int health;
	int attackPower;
	std::string zombieType;

public:
	Zombie();
	Zombie(int startingHealth, int startingAttackPower, std::string type = "Normal");

	int attack();
	void takeDamage(int damage);
	int getHealth() const;
	int getAttackPower() const;
	std::string getZombieType() const;
};