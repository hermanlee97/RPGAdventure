#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
using namespace std;

class Block{
    private:
        int x_coordinate;
        int y_coordinate;
        bool walkable;
        bool has_npc;
        bool has_enemy;
        //bool has_player;

    public:
        int get_x_coor(){return x_coordinate;}
        int get_y_coor(){return y_coordinate;}
        bool get_walkable(){return walkable;}
        bool get_has_npc(){return has_npc;}
        bool get_has_enemy(){return has_npc;}
        // bool get_has_player(){return has_player;}

        void set_x_coor(int x){x_coordinate = x;}
        void set_y_coor(int y){y_coordinate = y;}
        void set_walkable(bool w){walkable = w;}
        void set_has_npc(bool n){has_npc = n;}
        void set_has_enemy(bool e){has_enemy = e;}
        // void set_has_player(bool x){has_player = x;}

        Block(int x, int y, bool w, bool npc, bool e) {
            set_x_coor(x);
            set_y_coor(y);
            set_walkable(w);
            set_has_npc(npc);
            set_has_enemy(e);
        }

};


class Map {
    public:
        vector<vector<Block>> content;
        //generate map
        void make_map(string map_name);

        void print_map();

};

#endif 