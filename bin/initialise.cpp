#include <iostream>
#include <string>
#include <windows.h>

#include "entities.h"

void initialise(Player player, Enemy enemy)
{
    // Initialise player stats.
    player.hp = 10;
    player.gold = 0;
    player.damage = 5;
    player.defence = 2;

    player.x = 3;
    player.y = 3;

    // Test enemy stats.
    enemy.hp = 5;
    enemy.damage = 3;
    enemy.defence = 1;

    enemy.x = 4;
    enemy.y = 4;
}