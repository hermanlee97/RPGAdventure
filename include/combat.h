#ifndef COMBAT_H
#define COMBAT_H

#include "entities.h"
#include "map.h"
#include "printingSpaces.h"

using namespace std;

void has_combat(Map& map, Player& player);

int combat(Player& player, Enemy enemy);

#endif