#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// ## Personal header(.h) files ##
#include "entities.h"

//  ##################    MAIN FUNCTION       ###############
int main()
{
    // ON START (Load/NewGame functions)
    // {replace}
    system("CLS");

    Player player;

    // Starting position
    player.x = 3;
    player.y= 3;

    // ON UPDATE
    while (true)
    {

        // ## 1. World Change.  (New area/block loaded. Display the stuff onto the screen.) ##
        cout << "       Meadow" << endl;
        cout << "    X: " << player.getX << " Y: " << player.getY << endl;

        // ## 2. Event Presented. (Fight/Loot functions) ##
        // {replace}

        // ## 3. Futher Movement on the Map. (Move function (if the player did not die..)) ##
        // {replace}

        // ## 4. Wait. (For now) ##
        getchar();     // Waits till you press a button.
        system("CLS"); // Clears the Window.
    }

    return (0);
}
