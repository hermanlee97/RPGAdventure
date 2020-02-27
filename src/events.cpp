#include "../include/events.h"

std::string options(Map map, Block cur, Player player)
{

    int x = cur.get_x_coor();
    int y = cur.get_y_coor();
    // bool valid = false;

    while (true)
    {
        // ask for user input
        string choice;
        int intchoice;

        // cout << "W: move up    A: move left    S: move down    D: move right\n";
        // cout << "1: talk to npc    2: list inventory\n";
        // cout << "3: equip armour    4: unequip armour\n";
        // cout << "5: equip weapon    6: unequip weapon\n";
        // cout << "9: display stats    0: open world map" << endl;

        TextWindow(1, "W: move up A: move left\nS: move down D: move right\n1: talk to npc 2: list inventory\n3: equip armour 4: unequip armour\n5: equip weapon 6: unequip weapon\n9: display stats 0: open world");

        cin >> choice;

        // going left
        if (choice == "A" || choice == "a")
        {
            if (y - 1 >= 0)
            {
                Block left = map.get_block(x, y - 1);
                if (left.get_walkable())
                {
                    return ("left");
                    break;
                }
                else
                {
                    TextWindow(7, "You can't go to the left!");
                }
            }
            else
            {
                TextWindow(7, "There's nothing on the left!");
            }
        }

        // going right
        else if (choice == "D" || choice == "d")
        {
            if (y + 1 < map.get_content()[x].size())
            {
                Block right = map.get_block(x, y + 1);
                if (right.get_walkable())
                {
                    return ("right");
                    break;
                }
                else
                {
                    TextWindow(7, "You can't go to the right!");
                }
            }
            else
            {
                TextWindow(7, "There's nothing on the right!");
            }
        }

        // going up
        else if (choice == "W" || choice == "w")
        {
            if (cur.get_x_coor() - 1 >= 0)
            {
                Block up = map.get_block(x - 1, y);
                if (up.get_walkable())
                {
                    return ("up");
                    break;
                }
                else
                {
                    TextWindow(7, "You can't go up!");
                }
            }
            else
            {
                TextWindow(7, "There's nothing up there!");
            }
        }

        // going down
        else if (choice == "S" || choice == "s")
        {
            if (cur.get_x_coor() + 1 < map.get_content().size())
            {
                Block down = map.get_block(x + 1, y);
                if (down.get_walkable())
                {
                    return ("down");
                    break;
                }
                else
                {
                    TextWindow(7, "You can't go down!");
                }
            }
            else
            {
                TextWindow(7, "There's nothing down there!");
            }
        }

        // check npc option
        else if (choice == "1")
        {
            if (cur.get_has_npc())
            {
                TextWindow(7, "You've talked to the npc.");
            }
            else
            {
                TextWindow(7, "There's no npc here.");
            }
        }

        else if (choice == "2")
        {
            player.list_inventory();
        }

        else if (choice == "3")
        {
            player.list_armour();
            TextWindow(7, "Choose an item to equip.");
            cin >> intchoice;
            if (player.inventory[intchoice - 1].get_defence() == 0)
            {
                TextWindow(7, "There's no npc here.");
            }
            else
            {
                player.equip_armour(intchoice - 1);
            }
        }

        else if (choice == "4")
        {
            player.unequip_armour(0);
        }

        else if (choice == "5")
        {
            player.list_weapon();
            TextWindow(7, "There's no npc here.");
            cin >> intchoice;
            if (player.inventory[intchoice - 1].get_attack() == 0)
            {
                TextWindow(7, "That item has no attack.");
            }
            else
            {
                player.equip_weapon(intchoice - 1);
            }
        }

        else if (choice == "6")
        {
            player.unequip_weapon(0);
        }

        else if (choice == "9")
        {
            player.display_stat();
        }

        // print map
        else if (choice == "0")
        {
            map.print_map(player);
        }

        else
        {
            TextWindow(7, "Invalid Input");
        }
    }
}