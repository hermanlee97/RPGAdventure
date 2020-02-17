#include "menuOrLayout.h"

using namespace std;

// Replace the name with MainMenu().
int MainMenu()
{
    // START OF THE GAME
    system("CLS");

    MainMenuDisplay();

    char key;
    int hold = 0;

    while (1)
    {
        key = getch();

        if (key == '\r')
        {
            // Take the Value ur in and trigger the respective function.
            switch (hold)
            {
            case 0:
                // START()
                return 1;
                break;

            case 1:
                // LOAD()
                return 1;
                break;

            case 2:
                // EXIT()
                return 0;
                break;
            }
        }

        if (key == 's')
        {
            if (hold >= 3)
            {
                hold = 0;
            }
            else
            {
                hold += 1;
            }
        }
        Options(hold);

        if (key == 'w')
        {
            if (hold <= 0)
            {
                hold = 3;
            }
            else
            {
                hold -= 1;
            }
        }
        Options(hold);
    }

    // Move the selector.

    cin.get();

    return 0;
}

// Sets the position of cursore in console.
void SetPos(int x, int y)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {static_cast<short>(x), static_cast<short>(y)};
    SetConsoleCursorPosition(output, pos);
}

// Displays basic Menu options.
void MainMenuDisplay()
{
    // Display the options.
    SetPos(38, 12);
    cout << "Start";
    SetPos(36, 14);
    cout << "Load Game";
    SetPos(36, 16);
    cout << "Exit Game";

    // Display the first Arrow.
    SetPos(36, 12);
    cout << ">";
    SetPos(45, 16);
}

// Get's rid of the Arrows.
void ResetArrow()
{
    SetPos(36, 12);
    cout << " ";
    SetPos(34, 14);
    cout << " ";
    SetPos(34, 16);
    cout << " ";
}

// Let's you swap between the options.
void Options(int x)
{

    if (x == 0)
    {
        ResetArrow();
        SetPos(36, 12);
        cout << ">";
        SetPos(45, 16);
    }
    if (x == 1)
    {
        ResetArrow();
        SetPos(34, 14);
        cout << ">";
        SetPos(45, 16);
    }
    if (x == 2)
    {
        ResetArrow();
        SetPos(34, 16);
        cout << ">";
        SetPos(44, 16);
    }
}