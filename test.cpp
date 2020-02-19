#include <iostream>
#include "block.h"
#include "map.h"
#include "entities.h"

using namespace std;

int main() {
    Map m("map_02");
    Player p(1,1,2,3,4,5,6);
    m.print_mini_map(p);
}
