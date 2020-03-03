#ifndef COMBAT_H
#define COMBAT_H

#include "entities.h"
#include "printingSpaces.h"

using namespace std;

void combat(Player &player, Enemy enemy);
void playerTurn(Player &player,Enemy &enemy);
int getAttackTurn(int pspeed, int espeed);
void enemyTurn(Player &player,Enemy enemy);
int playerAttack(Player player,Enemy enemy);


#endif