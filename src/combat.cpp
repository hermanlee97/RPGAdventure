#include "../include/combat.h"

void has_combat(Map &map, Player &player)
{
    TextWindow(2, "X:" + to_string(player.get_x_coor()) + " Y:" + to_string(player.get_y_coor()));
    if (map.get_block(player.get_x_coor(), player.get_y_coor()).get_has_enemy())
    {
        if (map.get_block(player.get_x_coor(), player.get_y_coor()).get_spawn_count() == -1 || (player.get_steps() - map.get_block(player.get_x_coor(), player.get_y_coor()).get_spawn_count()) >= 10)
        {
            int new_hp = combat(player, map.get_block(player.get_x_coor(), player.get_y_coor()).get_enemy());
            if (new_hp > 0)
            {
                player.win(new_hp, map.get_block(player.get_x_coor(), player.get_y_coor()).get_enemy().get_gold(), map.get_block(player.get_x_coor(), player.get_y_coor()).get_enemy().get_xp());
                map.update_spawn_count(player.get_x_coor(), player.get_y_coor(), player.get_steps());
                TextWindow(7, to_string(map.get_block(player.get_x_coor(), player.get_y_coor()).get_spawn_count()));
            }
            else
            {
                player.lose();
            }
        }
    }
}
    

int combat(Player &player, Enemy enemy)
{
    int pHP = player.get_hp();
    int nHP = enemy.get_hp();

    while (nHP > 0 && pHP > 0)
    {
        // GIVE PLAYER CHOICE
        // system("CLS");
        string choice;

        while (true)
        {
            TextWindow(0, "                               \n                          \n");
            TextWindow(0, "Enemy Appears!\n\nYour HP: " + to_string(pHP) + "\nEnemy HP: " + to_string(nHP) + "\n\n1. Fight   2. Flee ");

            cin >> choice;

            if (choice == "1" || choice == "2")
            {
                break;
            }
            else
            {
                TextWindow(4, "Invalid input!");
            }
        }

        if (choice == "1")
        {
            // DEAL DAMAGE TO ENEMY
            if ((player.get_damage() - enemy.get_defence()) > 0)
            {
                // system("CLS");
                nHP -= player.get_damage() - enemy.get_defence();
                TextWindow(5, "You dealt " + to_string(player.get_damage() - enemy.get_defence()) + "\ndamage to the enemy!");
                // system("pause");
            }
            else
            {
                system("CLS");
                TextWindow(3, "The enemy deflected the blow!");
                // system("pause");
            }

            // CHECK IF THE ENEMY IS DEAD
            if (nHP <= 0)
            {
                // system("CLS");
                TextWindow(3, "The enemy has been defeated!");

                // system("pause");
                return pHP;
            }
            else
            {
                // DEAL DAMAGE TO PLAYER
                if ((enemy.get_damage() - player.get_damage()) > 0)
                {
                    // system("CLS");
                    pHP -= enemy.get_damage() - player.get_defence();
                    TextWindow(4, "The enemy dealt " + to_string(pHP) + " damage to you!");
                    // system("pause");
                }
                else
                {
                    // system("CLS");
                    TextWindow(4, "You deflected the blow!");
                    // system("pause");
                }
            }

            // CHECK IF THE PLAYER IS DEAD
            if (pHP <= 0)
            {
                TextWindow(3, "You have been defeated!");
                return 0;
            }
        }
        else if (choice == "2")
        {
            // system("CLS");
            // Since you're running take some damage. (Later loose some coins too.)
            pHP = player.get_hp() - enemy.get_damage();
            TextWindow(3, "The enemy managed to hit you        \nbefore you ran and dealt        \n" + to_string(enemy.get_damage()) + " damage to you!       \n");
            // player.gold = player.gold-(player.gold/100);
            // system("pause");
            return pHP;
        }

        else
        {
            TextWindow(4, "Invalid input!");
        }
    }
    return pHP;
}