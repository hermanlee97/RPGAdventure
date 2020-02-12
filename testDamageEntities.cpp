#include <iostream>
#include <windows.h>

// Include our FUNCTION files.
#include "entities.h"
#include "combat.h"
#include "flight.h"

int main()
{
    system("CLS");

    // Instantiate Objects.
    Player player;
    Enemy enemy;

    // Set PLAYER attributes.
    player.hp = 10;
    player.defence = 8;
    player.damage = 10;

    // Set ENEMY attributes.
    enemy.hp = 10;
    enemy.defence = 5;
    enemy.damage = 10;

    // COMBAT function.
    player.hp = combat(player, enemy);

    // FLIGHT function.
    // player.hp = flight(player, enemy);

    // Print the result.
    std::cout << player.hp << std::endl;
    std::cout << "DONE" << std::endl;

    return 0;
}
