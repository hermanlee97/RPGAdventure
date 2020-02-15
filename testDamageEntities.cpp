#include <iostream>

// Include our FUNCTION files.
#include "entities.h"
#include "combat.cpp"

int main()
{
    system("CLS");

    // Instantiate Objects.
    Player player(10, 0, 5, 2, 3, 3);
    Enemy enemy(5, 3, 1, 4, 4);

    // COMBAT function.
    player.hp = combat(player, enemy);

    // FLIGHT function.
    // player.hp = flight(player, enemy);

    // Print the result.
    std::cout << player.hp << std::endl;
    std::cout << "DONE" << std::endl;
    getchar();

    return 0;
}
