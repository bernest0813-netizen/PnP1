#include "Game.h"
#include <iostream>

void Game::start()
{
    bool playing = true;

    while (playing)
    {
        std::cout << "================================\n";
        std::cout << "   LAST STAND: ZOMBIE SURVIVAL\n";
        std::cout << "================================\n\n";

        std::cout << "A zombie has appeared!\n\n";

        combat();

        char choice;

        std::cout << "\nWould you like to play again? (y/n): ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y')
        {
            playing = false;
        }
        else
        {
            // Create a fresh player and zombie
            player = Player();
            zombie = Zombie();

            std::cout << "\nStarting a new game...\n\n";
        }
    }

    std::cout << "\nThanks for playing Last Stand!\n";
}

void Game::combat()
{
    int choice = 0;

    while (player.getHealth() > 0 && zombie.getHealth() > 0)
    {
        showStatus();

        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Heal\n";
        std::cout << "3. Run\n";
        std::cout << "\nChoose an option: ";

        std::cin >> choice;

        if (choice == 1)
        {
            int playerDamage = player.attack();
            zombie.takeDamage(playerDamage);

            if (zombie.getHealth() > 0)
            {
                int zombieDamage = zombie.attack();
                player.takeDamage(zombieDamage);
            }
        }
        else if (choice == 2)
        {
            player.heal();

            int zombieDamage = zombie.attack();
            player.takeDamage(zombieDamage);
        }
        else if (choice == 3)
        {
            std::cout << "\nYou ran away!\n";
            return;
        }
        else
        {
            std::cout << "\nInvalid choice. Please choose 1, 2, or 3.\n";
        }

        std::cout << "\n";
    }

    if (player.getHealth() <= 0)
    {
        std::cout << "================================\n";
        std::cout << "          GAME OVER\n";
        std::cout << "================================\n";
    }
    else if (zombie.getHealth() <= 0)
    {
        std::cout << "================================\n";
        std::cout << "       ZOMBIE DEFEATED!\n";
        std::cout << "================================\n";
    }
}

void Game::showStatus()
{
    std::cout << "Player Health: "
        << player.getHealth() << "\n";

    std::cout << "Zombie Health: "
        << zombie.getHealth() << "\n";
}