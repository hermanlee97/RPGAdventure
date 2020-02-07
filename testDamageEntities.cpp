#include <iostream>
#include <windows.h>

#include "entities.h"

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

    // Call the COMBAT method on player.
    player.hp = player.combat(player, enemy);

    // Print the result.
    std::cout << player.hp << std::endl;
    std::cout << "DONE" << std::endl;

    return 0;
}