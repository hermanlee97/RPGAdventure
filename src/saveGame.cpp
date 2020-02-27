#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Extra Functions
vector<string> LoadGame();
void SaveGame(int x, int y, string somethingElse);

// Main function for testing.
int main()
{

    // Loading Game Info (from file).
    vector<string> loadedInfo = LoadGame();

    cout << loadedInfo[0];
    cout << loadedInfo[1];

    //We use "_" to tell appart different data.
    SaveGame(5, 10, "Hello guys!");

    return 0;
}

// Load Game, puts stuff into a vector of strings (use itos(string) to convert it to ints.)
vector<string> LoadGame()
{
    vector<string> loadedInfo{"", ""};
    int hold = 0;

    ifstream myFile("save.txt");
    string line;

    getline(myFile, line);

    // Read the X and Y from the file.
    for (int i = 0; i < line.length(); i++)
    {
        // '_' - is used to separete each piece of data.
        if (line[i] == '_')
        {
            hold += 1;
        }
        else
        {
            if (hold == 0)
            {
                loadedInfo[0] += line[i];
            }
            else if (hold == 1)
            {
                loadedInfo[1] += line[i];
            }
        }
    }

    myFile.close();
    return loadedInfo;
}

void SaveGame(int x, int y, string somethingElse)
{
    ofstream myFile("save.txt");

    // Use "_" to separate different data.
    myFile << x << "_" << x << "_" << somethingElse;

    myFile.close();
}

