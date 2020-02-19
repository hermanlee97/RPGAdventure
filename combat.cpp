#include "entities.h"

using namespace std;

int combat(Player player, Enemy enemy)
{
    int pHP = player.get_hp();
    int nHP = enemy.get_hp();
    cout << "Enemy appears!" << endl;

    while (nHP > 0 && pHP > 0){
        // GIVE PLAYER CHOICE
        // system("CLS");
        string choice;

        while(true){
            cout << "Your HP: " << pHP << "\nEnemy HP: " << nHP << "\n 1. Fight\n 2. Flee\n" << endl;
            cin >> choice;
            if (choice == "1" || choice == "2") { break; }
            else { cout << "Invalid input!" << endl; }
        }

        if (choice == "1"){
            // DEAL DAMAGE TO ENEMY
            if ((player.get_damage() - enemy.get_defence()) > 0){
                // system("CLS");
                nHP -= player.get_damage() - enemy.get_defence();
                cout << "You dealt " << player.get_damage() - enemy.get_defence() << " damage to the enemy!" << endl;
                // system("pause");
            }
            else{
                system("CLS");
                cout << "The enemy deflected the blow!" << endl;
                // system("pause");
            }

            // CHECK IF THE ENEMY IS DEAD
            if (nHP <= 0){
                // system("CLS");
                cout << "The enemy has been defeated!\n" << endl;
                // system("pause");
                return pHP;
            }
            else {
                // DEAL DAMAGE TO PLAYER
                if ((enemy.get_damage() - player.get_damage()) > 0)
                {
                    // system("CLS");
                    pHP -= enemy.get_damage() - player.get_defence();
                    cout << "The enemy dealt " << enemy.get_damage() - player.get_defence() << " damage to you!\n" << endl;
                    // system("pause");
                }
                else
                {
                    // system("CLS");
                    cout << "You deflected the blow!\n" << endl;
                    // system("pause");
                }
            }

            // CHECK IF THE PLAYER IS DEAD
            if (pHP <= 0)
            {
                // Death function, END GAME LOOP
                // system("CLS");
                cout << "You have been defeated!\n" << endl;
                // system("pause");
                return 0;
            }
        }
        else if (choice == "2")
        {
            // system("CLS");
            // Since you're running take some damage. (Later loose some coins too.)
            pHP = player.get_hp() - enemy.get_damage();
            cout << "The enemy managed to hit you before you ran and dealt " << enemy.get_damage() << " damage to you!\n" << endl;
            // player.gold = player.gold-(player.gold/100);
            // system("pause");
            return pHP;
        }

        else
        {
            // system("CLS");
            cout << "Not a valid option." << endl;
        }
    }
    return pHP;
}