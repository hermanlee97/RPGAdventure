#include "entities.h"

int flight(Entity player, Entity enemy)
{
    int playerHP;

    // Since you're running take some damage. (Later loose some coins too.)
    playerHP = player.hp - enemy.damage;

    return playerHP;
}