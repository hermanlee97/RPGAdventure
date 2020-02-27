#include "../include/printingSpaces.h"

// Calculate how many lines need to
float CalculateLines(string story, int divider)
{
    float result = story.length() / divider;
    return result;
}

void TextWindow(int position, string story)
{
    // Window Constrains. ("Window" in which the text is.)
    int maxLineLength, x, y;

    // Set Position.
    switch (position)
    {
    // STORY Window.
    case 0:
        SetPos(5, 15);
        x = 5;
        y = 15;
        maxLineLength = 20;
        break;

    // Option Window.
    case 1:
        SetPos(5, 25);
        x = 5;
        y = 25;
        maxLineLength = 20;
        break;

    // Player HotBar.
    case 2:
        SetPos(10, 5);
        x = 10;
        y = 5;
        maxLineLength = 60;
        break;
    // Fight Messages.
    case 3:
        SetPos(45, 25);
        x = 45;
        y = 25;
        maxLineLength = 60;
        break;
    // Warning.
    case 4:
        SetPos(55, 29);
        x = 55;
        y = 29;
        maxLineLength = 60;
        break;

    // Game Scene Window.
    case 5:
        SetPos(30, 10);
        x = 50;
        y = 10;
        maxLineLength = 40;
        break;

    // Reward Window.
    case 6:
        SetPos(45, 20);
        x = 45;
        y = 20;
        maxLineLength = 40;
        break;
    // Fake Warning.
    case 7:
        SetPos(50, 29);
        x = 45;
        y = 29;
        maxLineLength = 60;
        break;
    }

    if (position != 1)
    {
        // Clear invalid input messages.
        if (position != 4)
        {
            SetPos(55, 29);
            cout << "                        \n                           \n                              ";
        }

        // Display text and set it to the right postition.
        int lenString = story.length();
        SetPos(x, y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        for (int i = 0; i < lenString; i++)
        {
            // Check for new line character, and correct the postion.
            if (story[i] == '\n')
            {
                y++;
                SetPos(x, y);
            }
            else
            {
                cout << story[i];
            }
        }
    }

    if (position == 1)
    {
        // Make all the options displayed properly
        int lenString = story.length();
        SetPos(x, y);
        for (int i = 0; i < lenString; i++)
        {
            // Check for new line character, and correct the postion.
            if (story[i] == '\n')
            {
                y++;
                SetPos(x, y);
            }
            else
            {
                // Colours
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                if (story[i] == 'W' || story[i] == 'A' || story[i] == 'S' || story[i] == 'D')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    cout << story[i];
                    cout << ":";
                }
                else if (story[i] == '1' || story[i] == '2' || story[i] == '3' || story[i] == '4' || story[i] == '5' || story[i] == '6')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                    cout << story[i];
                    cout << ":";
                }
                else if (story[i] == '0' || story[i] == '9')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                    cout << story[i];
                    cout << ":";
                }
                else if (story[i] != ':')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << story[i];
                }
            }
        }
    }

    // Not Used yet. Code made for display of stories.
    if (0)
    {
        // Check the Length of the Story.
        float lineNb = CalculateLines(story, maxLineLength);
        int roundedLineNb = (int)lineNb;

        vector<string> allLines;
        string copyStory = story;

        // Clean up the String. (Add "-" at the end of line if the word would get split.)
        for (int i = 0; i < roundedLineNb; i++)
        {
            allLines.push_back(copyStory.substr(0, maxLineLength));
            copyStory = copyStory.substr(maxLineLength, -1);

            if (allLines[i][9] == ' ')
            {
                continue;
            }
            else if (allLines[i][9] != ' ')
            {
                allLines[i].append("-");
            }
        }

        // Display the string.
        for (int i = 0; i < roundedLineNb; i++)
        {
            cout << allLines[i] << endl;
            SetPos(x, y + i + 1);
        }

        // Display the rest of the string.
        cout << copyStory;
    }

    SetPos(60, 30);
}
