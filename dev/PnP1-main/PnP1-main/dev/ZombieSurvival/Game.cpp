#include "Game.h"
#include <iostream>

void Game::start()
{
    std::cout << "================================\n";
    std::cout << "   LAST STAND: ZOMBIE SURVIVAL\n";
    std::cout << "================================\n\n";

    std::cout << "A zombie has appeared!\n\n";

    showStatus();
}

void Game::showStatus()
{
    std::cout << "Player Health: "
        << player.getHealth() << "\n";

    std::cout << "Zombie Health: "
        << zombie.getHealth() << "\n";
}