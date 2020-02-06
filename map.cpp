#include <iostream>
#include <tuple>
using namespace std;

class map {
    private:
        tuple<int, int> coordinates = {0,0};
        bool walkable = false;
        bool has_npc = false;
        bool has_enemy = false;
        bool has_player = false;

    public:
        //return coordinate
        void get_coor(){
            ;
        }

        //generate map
        void make_map(int x, int y){
            ;
        }

};