#include "Game.h"
#include <iostream>

Game::Game()
{
    currentWave = 1;
}

void Game::start()
{
    bool playing = true;

    while (playing)
    {
        player = Player();
        currentWave = 1;

        bool survived = true;

        while (survived)
        {
            zombies.clear();

            int zombieCount = currentWave + 2;

            int zombieHealth = 50 + (currentWave - 1) * 10;
            int zombieDamage = 10 + (currentWave - 1) * 2;

            for (int i = 0; i < zombieCount; i++)
            {
                zombies.push_back(Zombie(zombieHealth, zombieDamage));
            }

            std::cout << "================================\n";
            std::cout << "   LAST STAND: ZOMBIE SURVIVAL\n";
            std::cout << "================================\n";
            std::cout << "\nWAVE " << currentWave << "!\n";
            std::cout << zombieCount << " zombies approach!\n\n";

            combat();

            if (player.getHealth() <= 0)
            {
                survived = false;
            }
            else
            {
                std::cout << "\n================================\n";
                std::cout << "       WAVE " << currentWave << " CLEARED!\n";
                std::cout << "================================\n";

                std::cout << "Health remaining: "
                    << player.getHealth() << "\n";

                std::cout << "Score: "
                    << player.getScore() << "\n";

                std::cout << "\nPress ENTER to continue to the next wave...";
                std::cin.ignore(10000, '\n');
                std::cin.get();

                currentWave++;
            }
        }

        std::cout << "\n================================\n";
        std::cout << "          GAME OVER\n";
        std::cout << "================================\n";
        std::cout << "Final Score: " << player.getScore() << "\n";

        char choice;

        std::cout << "\nWould you like to play again? (y/n): ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y')
        {
            playing = false;
        }
        else
        {
            std::cout << "\nStarting a new game...\n\n";
        }
    }

    std::cout << "\nThanks for playing Last Stand!\n";
}

void Game::combat()
{
    int choice = 0;

    while (player.getHealth() > 0)
    {
        if (zombies.empty())
        {
            return;
        }

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

            zombies.front().takeDamage(playerDamage);

            if (zombies.front().getHealth() <= 0)
            {
                std::cout << "\nZombie defeated! +10 points!\n";
                player.addScore(10);
                zombies.erase(zombies.begin());
            }

            if (!zombies.empty())
            {
                int zombieDamage = zombies.front().attack();
                player.takeDamage(zombieDamage);
            }
        }
        else if (choice == 2)
        {
            player.heal();

            int zombieDamage = zombies.front().attack();
            player.takeDamage(zombieDamage);
        }
        else if (choice == 3)
        {
            std::cout << "\nYou ran away!\n";
            player.takeDamage(player.getHealth());
        }
        else
        {
            std::cout << "\nInvalid choice. Please choose 1, 2, or 3.\n";
        }

        std::cout << "\n";
    }
}

void Game::showStatus()
{
    std::cout << "\nPlayer Health: "
        << player.getHealth() << "\n";

    std::cout << "Current Wave: "
        << currentWave << "\n";

    std::cout << "Zombies Remaining: "
        << zombies.size() << "\n";

    if (!zombies.empty())
    {
        std::cout << "Current Zombie Health: "
            << zombies.front().getHealth() << "\n";

        std::cout << "Current Zombie Attack Power: "
            << zombies.front().getAttackPower() << "\n";
    }

    std::cout << "Score: "
        << player.getScore() << "\n";
}