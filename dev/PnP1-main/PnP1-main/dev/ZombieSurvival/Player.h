#pragma once

class Player
{
private:
	int health;
	int attackPower;
	int score;

public:
	Player();

	int attack();
	void takeDamage(int damage);
	void heal();
	void rewardHealth();

	int getHealth() const;
	int getScore() const;
	void addScore(int points);
};
