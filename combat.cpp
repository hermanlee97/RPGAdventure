#include "entities.h"

int combat(Player player, Enemy enemy)
{
    int pHP = player.hp;
    int nHP = enemy.hp;

    while (nHP > 0 && pHP > 0)
    {
        // GIVE PLAYER CHOICE
        system("CLS");
        int choice;
        std::cout << "Your HP: " << pHP << "\nEnemy HP: " << nHP << "\n 1. Fight\n 2. Flee" << std::endl;
        std::cin >> choice;

        if (choice == 1)
        {
            // DEAL DAMAGE TO ENEMY
            if ((enemy.defence - player.damage) < 0)
            {
                system("CLS");
                nHP -= player.damage - enemy.defence;
                std::cout << "You dealt " << player.damage - enemy.defence << " damage to the enemy!" << std::endl;
                system("pause");
            }
            else
            {
                system("CLS");
                std::cout << "The enemy deflected the blow!" << std::endl;
                nHP -= 0;
                system("pause");
            }

            // CHECK IF THE ENEMY IS DEAD
            if (nHP <= 0)
            {
                system("CLS");
                std::cout << "The enemy has been defeated!" << std::endl;
                system("pause");
                return pHP;
            }
            else
            {
                // DEAL DAMAGE TO PLAYER
                if ((player.defence - enemy.damage) < 0)
                {
                    system("CLS");
                    pHP -= enemy.damage - player.defence;
                    std::cout << "The enemy dealt " << enemy.damage - player.defence << " damage to you!" << std::endl;
                    system("pause");
                }
                else
                {
                    system("CLS");
                    std::cout << "You deflected the blow!" << std::endl;
                    pHP -= 0;
                    system("pause");
                }
            }

            // CHECK IF THE PLAYER IS DEAD
            if (pHP <= 0)
            {
                // Death function, END GAME LOOP
                system("CLS");
                std::cout << "You have been defeated!" << std::endl;
                system("pause");
                return 0;
            }
        }
        else if (choice == 2)
        {
            system("CLS");
            // Since you're running take some damage. (Later loose some coins too.)
            pHP = player.hp - enemy.damage;
            std::cout << "The enemy dealt " << enemy.damage - player.defence << " damage to you!" << std::endl;
            // player.gold = player.gold-(player.gold/100);
            system("pause");
            return pHP, player.moveX("L");
        }

        else
        {
            system("CLS");
            std::cout << "Not a valid option." << std::endl;
        }
    }
    return pHP;
}