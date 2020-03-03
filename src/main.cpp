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
    Skill_Tree st;
    Player player(0, 0, 10, 5, 2, 1000, 0, st);

    // for testing
    player.set_skill_point(2);

    // test items
    Armour *test_armour = new Armour("Test Armour", 100, 5);
    Weapon *test_sword = new Weapon("Test Sword", 100, 5);
    player.add_armour(test_armour);
    player.add_weapon(test_sword);

    string action;
    // Game loop
    while (true)
    {
        system("CLS");

        // ## 1. Check if there is combat ##
        if (has_combat(world_map, player))
        {
            combat(world_map, player, world_map.get_block(player.get_x_coor(), player.get_y_coor()).get_enemy());
        }

        // ## 2. Event Presented + other options ##
        action = options(world_map, player);

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