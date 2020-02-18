#include "printingSpaces.h"

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

    // Game Scene Window.
    case 3:
        SetPos(30, 10);
        x = 30;
        y = 10;
        maxLineLength = 40;
        break;
    }

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
    if (lineNb != roundedLineNb)
    {
        cout << copyStory;
    }
}

