#include <iostream>
#include <vector>

#include "entities.h"

using namespace std;

int shop(Player player, NPC npc) {
    vector<Item*> tempInventory = player.get_inventory();
    int tempGold = player.get_gold();
    
    npc.refresh_equipment();
    int buy_in_while = 0;
    int intchoice = 0;
    while (buy_in_while != 1) {
        npc.list_equipment();
        cout << "You have " << tempGold << " gold." << endl;
        cout << "1. Buy    2. Sell    3. Exit" << endl;
        cin >> intchoice;
        if (intchoice == 1) {
            int intchoice_buy = 0;
            cout << "Which item would you like to buy?" << endl;
            cin >> intchoice_buy;
            if (tempGold < npc.get_vendor_item(intchoice_buy)->get_cost()) {
                cout << "You don't have enough money to buy that item." << endl;
            }
            else if (tempGold >= npc.get_vendor_item(intchoice_buy)->get_cost()) {
                player.add_item(npc.get_vendor_item(intchoice_buy));
                tempGold -= npc.get_vendor_item(intchoice_buy)->get_cost();
                npc.remove_item(intchoice_buy);
            }
            else {
                cout << "Invalid item." << endl;
            }
        }

        else if (intchoice == 3) {
            buy_in_while = 1;
        }
    }
    return tempGold;
}