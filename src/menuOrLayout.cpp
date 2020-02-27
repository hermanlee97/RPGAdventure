#include "../include/menuOrLayout.h"

using namespace std;

void Rain(int x, int y, string weather);
void Anim(int posX, int posY, string weather);
void WeatherDecider();

bool isDone = false;
string mainWeather = "windy";
int posX = 0;
int posY = 0;

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
        WeatherDecider();
        if (kbhit())
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
    }

    // Move the selector.

    cin.get();

    return 0;
}

// Sets the position of cursor in console.
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

// Animation
void Rain(int x, int y, string weather)
{
    if (weather == "rainy")
    {
        // Clear The old texts.
        if (y == 0)
        {
            SetPos(x, 39);
            cout << " ";
        }
        else
        {

            SetPos(x, y - 1);
            cout << " ";
        }

        // Print new Stuff out.
        if (y > 40)
        {
            y = y - 40;
        }
        SetPos(x, y);
        cout << "V";
    }
    else if (weather == "windy")
    {
        // Reset the position.
        if (x > 80)
        {
            x = x - 80;
        }

        // Print new Stuff out.
        SetPos(x, y);
        cout << "~";

        // Clear The old texts.
        if (x == 0)
        {
            SetPos(79, y);
            cout << " ";
        }
        else if (x != 0 && x < 80)
        {

            SetPos(x - 1, y);
            cout << " ";
        }
    }
}

void Anim(int posX, int posY, string weather)
{
    Rain(1 + posX, 5 + posY, weather);
    // Rain(5 + posX, 13 + posY, weather);
    Rain(7 + posX, 11 + posY, weather);
    Rain(12 + posX, 31 + posY, weather);
    Rain(21 + posX, 27 + posY, weather);
    Rain(2 + posX, 22 + posY, weather);
    Rain(35 + posX, 5 + posY, weather);
    Rain(43 + posX, 3 + posY, weather);
    // Rain(58 + posX, 13 + posY, weather);
    Rain(65 + posX, 11 + posY, weather);
    Rain(78 + posX, 1 + posY, weather);
}

void WeatherDecider()
{

    Sleep(10);
    if (mainWeather == "windy")
    {
        if (posX < 80)
        {
            Anim(posX, posY, mainWeather);
            posX += 1;
        }
        else
        {
            posX = 0;
        }
    }
    else if (mainWeather == "rainy")
    {
        if (posY < 40)
        {
            Anim(posX, posY, mainWeather);
            posY += 1;
        }
        else
        {
            posY = 0;
        }
    }
}
