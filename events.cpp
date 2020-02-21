#include <iostream>
#include <string>
#include <vector>
#include "map.h"
#include "entities.h"
#include "combat.h"
using namespace std;

std::string options(Map map, Block cur, Player player){

    int x = cur.get_x_coor();
    int y = cur.get_y_coor();
    // bool valid = false;

    while (true) {
        // ask for user input
        string choice;
        int intchoice;
        cout << "W: move up    A: move left    S: move down    D: move right\n";
        cout << "1: talk to npc    2: list inventory\n";
        cout << "3: equip armour    4: unequip armour\n";
        cout << "5: equip weapon    6: unequip weapon\n";
        cout << "9: display stats    0: open world map" << endl;
        cin >> choice;

        // going left 
        if (choice == "A" || choice == "a") {
            if (y-1 >= 0){
                Block left = map.get_block(x,y-1);
                if (left.get_walkable()){
                    return("left");
                    break;
                }
                else { cout << "You can't go to the left!" << endl; }
            }
            else { cout << "There's nothing on the left!" << endl; }
        }
        
        // going right 
        else if (choice == "D" || choice == "d") {
            if (y+1 < map.get_content()[x].size()) {
                Block right = map.get_block(x,y+1);
                if (right.get_walkable()){
                    return("right");
                    break;
                }
                else { cout << "You can't go to the right!" << endl; }
            }
            else { cout << "There's nothing on the right!" << endl; }

        }

        // going up
        else if (choice == "W" || choice == "w") {
            if (cur.get_x_coor()-1 >= 0){
                Block up = map.get_block(x-1,y);
                if (up.get_walkable()){
                    return("up");
                    break;
                }
                else { cout << "You can't go up!" << endl; }
            }
            else { cout << "There's nothing up there!" << endl; }
        }

        // going down
        else if (choice == "S" || choice == "s") {
            if (cur.get_x_coor()+1 < map.get_content().size()){
                Block down = map.get_block(x+1,y);
                if (down.get_walkable()){
                    return("down");
                    break;
                }
                else { cout << "You can't go down!" << endl; }
            }
            else { cout << "There's nothing down there!" << endl; }
        }

        // check npc option
        else if (choice == "1") {
            if (cur.get_has_npc()){
                cout << "You've talked to the npc." << endl;    // change to npc interaction later.
            }
            else { cout << "There's no npc here." << endl;}
        }

        else if (choice == "2"){
            player.list_inventory();
        }

        else if (choice == "3"){
            player.list_armour();
            cout << "Choose an item to equip." << endl;
            cin >> intchoice;
            if (player.get_inventory_item(intchoice - 1)->get_defence() == 0){
                cout << "That item has no defence." << endl;
            }
            else{
                player.equip_armour(intchoice - 1);
            }
        }

        else if (choice == "4"){
            player.unequip_armour(0);
        }

        else if (choice == "5"){
            player.list_weapon();
            cout << "Choose an item to equip." << endl;
            cin >> intchoice;
            if (player.get_inventory_item(intchoice - 1)->get_defence() == 0){
                cout << "That item has no attack." << endl;
            }
            else{
                player.equip_weapon(intchoice - 1);
            }
        }

        else if (choice == "6"){
            player.unequip_weapon(0);
        }

        else if (choice == "9") {
            player.display_stat();
        }

        // print map
        else if (choice == "0") {
            map.print_map(player);
        }

        else { cout << "Invalid input!" << endl; }

    }

}