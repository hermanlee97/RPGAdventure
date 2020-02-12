#include <iostream>
#include "map.h"
#include "events.h"
using namespace std;

int main() {
    // Map map1;
    // map1.make_map("map_01");
    // map1.print_map();
    Map map2;
    map2.make_map("map_02");
    map2.print_map();
    options(map2, 2, 1);
    return 0;
}