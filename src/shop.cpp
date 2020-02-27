#include "../include/shop.h"

int shop(Player player, NPC npc)
{
    int tempGold = player.get_gold();

    npc.refresh_equipment();
    int buy_in_while = 0;
    int intchoice = 0;
    while (buy_in_while != 1)
    {
        npc.list_equipment();
        TextWindow(7, "You have " + to_string(tempGold) + " gold.");
        TextWindow(6, "1. Buy    2. Sell    3. Exit");
        cin >> intchoice;
        if (intchoice == 1)
        {
            int intchoice_buy = 0;
            TextWindow(6, "Which item would you like to buy?");
            cin >> intchoice_buy;
            if (tempGold < npc.get_vendor_item(intchoice_buy)->get_cost())
            {
                TextWindow(7, "You don't have enough money.");
            }
            else if (tempGold >= npc.get_vendor_item(intchoice_buy)->get_cost())
            {
                player.add_item(npc.get_vendor_item(intchoice_buy));
                tempGold -= npc.get_vendor_item(intchoice_buy)->get_cost();
                npc.remove_item(intchoice_buy);
            }
            else
            {
                TextWindow(4, "invalid item.");
            }
        }

        else if (intchoice == 3)
        {
            buy_in_while = 1;
        }
    }
    return tempGold;
}