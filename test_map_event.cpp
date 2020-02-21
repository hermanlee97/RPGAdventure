#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "map.h"
#include "block.h"
#include "entities.h"
// #include "events.h"
using namespace std;


int main() {
    Map world_map("map_02");
    Player player(1,1,0,0,0,0,0);
    world_map.print_mini_map(player);
    world_map.print_map(player);

    return 0;
}