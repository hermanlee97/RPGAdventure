#ifndef COMBAT_H
#define COMBAT_H

#include "entities.h"
#include "flight.h"

int combat(Player player, Enemy enemy)
{
    int pHP = player.hp;
    int nHP = enemy.hp;

    while (nHP > 0 && pHP > 0)
    {
        // GIVE PLAYER CHOICE
        int choice;
        std::cout << "\nYour HP: " << pHP << " Enemy HP: " << nHP << ".\n 1. Fight\n 2. Flee" << std::endl;
        std::cin >> choice;

        if (choice == 1)
        {
            // DEAL DAMAGE TO ENEMY
            if ((enemy.defence - player.damage) < 0)
            {
                nHP -= player.damage - enemy.defence;
                std::cout << "\nYou dealt " << player.damage - enemy.defence << " damage to the enemy!" << std::endl;
            }
            else
            {
                std::cout << "\nThe enemy deflected the blow!" << std::endl;
                nHP -= 0;
            }

            // CHECK IF THE ENEMY IS DEAD
            if (nHP <= 0)
            {
                std::cout << "\nThe enemy has been defeated!" << std::endl;
                return pHP;
            }
            else
            {
                // DEAL DAMAGE TO PLAYER
                if ((player.defence - enemy.damage) < 0)
                {
                    pHP -= enemy.damage - player.defence;
                    std::cout << "\nThe enemy dealt " << enemy.damage - player.defence << " damage to you!" << std::endl;
                }
                else
                {
                    std::cout << "\nYou! deflected the blow!" << std::endl;
                    pHP -= 0;
                }
            }

            // CHECK IF THE PLAYER IS DEAD
            if (pHP <= 0)
            {
                // Death function, END GAME LOOP
                std::cout << "\nYou have been defeated!" << std::endl;
                return 0;
            }
        }
        else if (choice == 2)
        {
            pHP = flight(player, enemy);
            return pHP;
        }

        else
            std::cout << "\nNot a valid option." << std::endl;
    }
    return pHP;
}

#endif