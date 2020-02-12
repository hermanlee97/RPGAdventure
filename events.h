// #include <iostream>
// #include <string>
// #include "map.h"
// using namespace std;

// void combat_encounter(Map map, int x, int y);

// void options(Map map, int x, int y);


#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include <string>
#include <vector>
#include "map.h"
using namespace std;

// void combat_encounter(Map map, int x, int y){
//     if (map.content[x][y].get_has_enemy()){
//         cout << "Enemy appears!" << endl;
//         cout << "1. fight       2. flee" << endl;
//     }

// }

void options(Map map, int x, int y){
    int choice;
    Block cur = map.content[x][y];
    // check if there is enemy
    if (cur.get_has_enemy()){
        cout << "Enemy appears!" << endl;
        cout << "1. fight       2. flee" << endl;
        // cin >> choice;
        // if (choice == 1){;}     // combat
        // else {;}    // flee
    }

    string ops;
    int count = 1;
    // check left side
    if (cur.get_y_coor()-1 >= 0){
        Block left = map.content[x][y-1];
        if (left.get_walkable()){
            ops.append(to_string(count) + ". go left        ");
            count += 1;
        }
    }
    // check right side
    if (cur.get_y_coor()+1 < map.content[x].size()){
        Block right = map.content[x][y+1];
        if (right.get_walkable()){
            ops.append(to_string(count) + ". go right        ");
            count += 1;
        }
    }
    // check top side
    if (cur.get_x_coor()-1 >= 0){
        Block up = map.content[x-1][y];
        if (up.get_walkable()){
            ops.append(to_string(count) + ". go up        ");
            count += 1;
        }
    }
    // check bottom side
    if (cur.get_x_coor()+1 < map.content.size()){
        Block down = map.content[x+1][y];
        if (down.get_walkable()){
            ops.append(to_string(count) + ". go down        ");
            count += 1;
        }
    }
    // check npc option
    if (cur.get_has_npc()){
        ops.append(to_string(count) + ". talk to npc        ");
        count += 1;
    }

    cout << ops << endl;
    // cin >> choice;
    // if ...


}

#endif