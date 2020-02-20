#include <iostream>

// Include our FUNCTION files.
#include "entities.h"
#include "combat.cpp"
#include "map.h"
#include "block.h"

int main()
{
    system("CLS");

    // Instantiate Objects.
    Map world_map("map_02");
    Player player(1, 1, 10, 5, 2, 0, 0);
    player.set_steps(10);
    Block cur = world_map.get_block(player.get_x_coor(), player.get_y_coor());

        // ## 1. Check if there is combat ##
        if (cur.get_has_enemy() && cur.get_enemy().get_spawn() == 0 && (player.get_steps() - cur.get_enemy().get_spawn())>=10)
        {
            int new_hp = combat(player, cur.get_enemy());
            if (new_hp > 0)
            {
                player.win(new_hp, cur.get_enemy().get_gold(), cur.get_enemy().get_xp());
                cur.get_enemy().defeated(player);
                // cout << "You have " << player.get_hp() << " hp left.\n" << endl;
            }
            else
            {
                player.lose();
            }
        }

    return 0;
}
