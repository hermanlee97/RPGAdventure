#include "entities.h"

int flight(Player player, Enemy enemy)
{
    system("CLS");
    int fHP;
    // Since you're running take some damage. (Later loose some coins too.)
    fHP = player.hp - enemy.damage;
    std::cout << "\nThe enemy dealt " << enemy.damage - player.defence << " damage to you!" << std::endl;
    getchar();
    // player.gold = player.gold-(player.gold/100);
    return fHP;
}