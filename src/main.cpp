#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// ## Personal header(.h) files ##
#include "../include/entities.h"
#include "../include/combat.h"
#include "../include/map.h"
#include "../include/block.h"
#include "../include/events.h"
#include "../include/menuOrLayout.h"
#include "../include/printingSpaces.h"

//  ##################    MAIN FUNCTION       ###############
int main()
{
    // ON START (Load/NewGame functions)
    int shouldStart = MainMenu();

    // TO EXIT the Game
    if (shouldStart == 0)
    {
        return 0;
    }

    Map world_map("map_02");
    Player player(0, 0, 10, 5, 2, 0, 0);

    // Test items
    Equipment test_armour("Test Armour", 0, 2);
    Equipment test_sword("Test Sword", 1, 0);
    player.add_item(test_armour);
    player.add_item(test_sword);

    string action;
    // Game loop
    while (true)
    {
        system("CLS");
        Block cur = world_map.get_block(player.get_x_coor(), player.get_y_coor());

        // Using proper Function to display stuff. (2=hotbar, string to be displayed).
        TextWindow(2, "X:" + to_string(player.get_x_coor()) + " Y:" + to_string(player.get_y_coor()));

        // ## 1. Check if there is combat ##
        if (cur.get_has_enemy())
        {
            int new_hp = combat(player, cur.get_enemy());
            if (new_hp > 0)
            {
                player.win(new_hp, cur.get_enemy().get_gold(), cur.get_enemy().get_xp());
                // cout << "You have " << player.get_hp() << " hp left.\n" << endl;
            }
            else
            {
                player.lose();
                continue;
            }
        }

        // ## 2. Event Presented + other options ##
        action = options(world_map, cur, player);

        if (action == "left")
        {
            player.move_left();
        }
        else if (action == "right")
        {
            player.move_right();
        }
        else if (action == "up")
        {
            player.move_up();
        }
        else if (action == "down")
        {
            player.move_down();
        }
        else
        {
            TextWindow(4, "INVALID ACTION");
        }
    }

    return 0;
}