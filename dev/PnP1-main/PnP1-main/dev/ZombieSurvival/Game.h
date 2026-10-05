#pragma once
#include "Player.h"
#include "Zombie.h"

class Game
{
private:
	Player player;
	Zombie zombie;

public:
	void start();
	void showStatus();
	void combat();
};
