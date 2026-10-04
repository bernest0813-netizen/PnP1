#pragma once

class Zombie
{
private:
	int health;
	int attackPower;

public:
	Zombie();

	int attack();
	void takeDamage(int damage);

	int getHealth() const;
};