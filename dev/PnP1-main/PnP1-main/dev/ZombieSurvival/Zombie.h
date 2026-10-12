#pragma once

class Zombie
{
private:
	int health;
	int attackPower;

public:
	Zombie();
	Zombie(int startingHealth, int startingAttackPower);

	int attack();
	void takeDamage(int damage);
	int getHealth() const;
	int getAttackPower() const;
};