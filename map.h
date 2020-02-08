#include <iostream>
#include <tuple>
#include <array>
#include "block.h"
using namespace std;

class Map {
    private:
        vector<Block> content = {};
        tuple<int, int> coordinates = {0,0};
        bool walkable = false;
        bool has_npc = false;
        bool has_enemy = false;
        //bool has_player = false;

    public:
        tuple<int, int> get_coor(){return coordinates;}
        void set_coor(tuple<int, int> x){coordinates = x;}
        bool get_walkable(){return walkable;}
        void set_walkable(bool x){walkable = x;}
        bool get_has_npc(){return has_npc;}
        void set_has_npc(bool x){has_npc = x;}
        bool get_has_enemy(){return has_npc;}
        void set_has_enemmy(bool x){has_enemy = x;}

        // bool get_has_player(){return has_player;}
        // void set_has_player(bool x){has_player = x;}

        //generate map
        void make_map(int x, int y);

        void print_map();

};