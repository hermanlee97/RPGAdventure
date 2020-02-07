#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// ## Personal header(.h) files ##
// {replace}
// {replace}

//  ##################    MAIN FUNCTION       ###############
int main()
{
    // ON START (Load/NewGame functions)
    // {replace}
    system("CLS");

    // Starting position
    int xPos = 3;
    int yPos = 3;

    // ON UPDATE
    while (true)
    {

        // ## 1. World Change.  (New area/block loaded. Display the stuff on the screen.) ##
        cout << "       Meadow" << endl;
        cout << "    X: " << xPos << " Y: " << yPos << endl;

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
