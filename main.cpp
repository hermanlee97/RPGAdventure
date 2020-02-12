#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// ## Personal header(.h) files ##
#include "entities.h"
#include "combat.h"

//  ##################    MAIN FUNCTION       ###############
int main()
{
    Player player(10, 0, 5, 2, 3, 3);
    Enemy enemy(5, 3, 1, 4, 4);

    // ON START (Load/NewGame functions)
    std::string choice;
    system("CLS");

    // ON UPDATE
    while (true)
    {
        // ## 1. Event Presented. (Fight/Loot functions) ##
        if(player.x == enemy.x && player.y == enemy.y)
        {
            system("CLS");
            player.hp == combat(player, enemy);
        }


        // ## 2. World Change.  (New area/block loaded. Display the stuff onto the screen.) ##
        cout << "    Green Hill Zone" << endl;
        cout << "    X: " << player.x << " Y: " << player.y << endl;
        cout << "    HP: " << player.hp << " ATK: " << player.damage << " DEF: " << player.defence << endl;


        // ## 3. Futher Movement on the Map. (Move function (if the player did not die..)) ##
        if (choice == "L" || choice == "R" || choice == "l" || choice == "r")
        {
            player.moveX(choice);
        }
        else if(choice == "U" || choice == "D" || choice == "u" || choice == "d")
        {
            player.moveY(choice);
        }

        // ## 4. Wait. (For now) ##
        choice = getchar(); // Waits till you press a button.

        system("CLS"); // Clears the Window.
    }

    return (0);
}