#pragma once
#include "Player.h"
#include "Zombie.h"
#include <vector>

class Game
{
private:
	Player player;
	std::vector<Zombie> zombies;
	int currentWave;

public:
	Game();


	void start();
	void showStatus();
	void combat();
};
