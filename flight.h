#ifndef FLIGHT_H
#define FLIGHT_H

#include "entities.h"

int flight(Entity player, Entity enemy)
{
    int fHP;
    // Since you're running take some damage. (Later loose some coins too.)
    fHP = player.hp - enemy.damage;
    std::cout << "\nThe enemy dealt " << enemy.damage - player.defence << " damage to you!" << std::endl;
    // player.gold = player.gold-(player.gold/100);
    return fHP;
}

#endif