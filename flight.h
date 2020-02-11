#include "entities.h"

void flight(Entity player, Entity enemy)
{
    // Since you're running take some damage. (Later loose some coins too.)
    player.hp = player.hp - enemy.damage;
    // player.gold = player.gold-(player.gold/100);

}