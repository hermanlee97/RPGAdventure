#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// ## Personal header(.h) files ##
#include "entities.h"
#include "combat.h"
#include "map.h"
#include "block.h"
#include "events.h"

//  ##################    MAIN FUNCTION       ###############
int main() {
    // ON START (Load/NewGame functions)
    Map world_map("map_02");
    Player player(0, 0, 10, 5, 2, 0, 0);
    string action;

    // game loop
    while (true)
    {
        system("clear");
        Block cur = world_map.get_block(player.get_x_coor(),player.get_y_coor());
        cout << "You are now at (" << player.get_x_coor() << "," << player.get_y_coor() << "). \n" << endl;

        // ## 1. Check if there is combat ##
        if (cur.get_has_enemy()){
            int new_hp = combat(player, cur.get_enemy());
            if (new_hp > 0) {
                player.win(new_hp, cur.get_enemy().get_gold(), cur.get_enemy().get_xp());
                // cout << "You have " << player.get_hp() << " hp left.\n" << endl;
            } else { player.lose(); continue; }
        }

        // ## 2. Event Presented + other options ##
        action = options(world_map, cur, player);

        if (action == "left") { player.move_left(); }
        else if (action == "right") { player.move_right(); }
        else if (action == "up") { player.move_up(); }
        else if (action == "down") { player.move_down(); }
        else { cout << "INVALID ACTION" << endl; }
    }

    return 0;
}