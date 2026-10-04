#pragma once

class Zombie
{
private:
	int health;
	int attackPower;

public:
	Zombie();

	void attack();
	void takeDamage(int damage);

	int getHealth() const;
};