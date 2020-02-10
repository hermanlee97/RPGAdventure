#include <iostream>
#include <string>
#include "events.h"
using namespace std;

void check_combat(map, x, y) {
    if (map.content[x][y].get_has_enemy()){
        cout << "Enemy appears!" << endl;
        cout << "1. fight       2. flight" << endl;
    }

}
void options(map, x, y) {
    Block cur = map.content[x][y];
    Block left = map.content[x-1][y];
    Block right = map.content[x+1][y];
    Block up = map.content[x][y-1];
    Block down = map.content[x][y+1];

    string ops;
    int count = 1;
    if (left.get_walkable()){
        ops.append(to_string(count) + ". go left        ");
        count += 1;
    }
    if (right.get_walkable()){
        ops.append(to_string(count) + ". go right        ");
        count += 1;
    }
    if (up.get_walkable()){
        ops.append(to_string(count) + ". go up        ");
        count += 1;
    }
    if (down.get_walkable()){
        ops.append(to_string(count) + ". go down        ");
        count += 1;
    }
    if (cur.get_has_npc()){
        ops.append(to_string(count) + ". talk to npc        ");
        count += 1;
    }

    cout << ops << endl;
}