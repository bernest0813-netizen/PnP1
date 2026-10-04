#include "Game.h"
#include <iostream>


void Game::start()
{
    std::cout << "================================\n";
    std::cout << "   LAST STAND: ZOMBIE SURVIVAL\n";
    std::cout << "================================\n\n";

    std::cout << "A zombie has appeared!\n\n";

    int playerDamage = player.attack();

    zombie.takeDamage(playerDamage);

    std::cout << "\nZombie Health: "
        << zombie.getHealth() << "\n\n";

    if (zombie.getHealth() > 0)
    {
        int zombieDamage = zombie.attack();

        player.takeDamage(zombieDamage);

        std::cout << "Player Health: "
            << player.getHealth() << "\n";
    }
}