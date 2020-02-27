#include <iostream>
#include "entities.h"
using namespace std;


int main() {
    Player p(2,1,10,5,3,0,0);
    // p.move_right();
    // cout << p.get_x_coor() << endl;
    // cout << p.get_y_coor() << endl;

    p.display_stat();

    return 0;

}