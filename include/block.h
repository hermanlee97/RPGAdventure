#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>
#include <string>

#include "entities.h"

using namespace std;

class Block{
    private:
        int x_coordinate;
        int y_coordinate;
        bool walkable;
        bool has_npc;
        vector<NPC> npc;
        vector<Enemy> enemy;
        int spawn_count;

    public:
        int get_x_coor(){return x_coordinate;}
        int get_y_coor(){return y_coordinate;}
        bool get_walkable(){return walkable;}
        bool get_has_npc(){
            if (npc.size() == 0) {return false;}
            else {return true;}
        }
        NPC get_npc(){return npc[0];}
        bool get_has_enemy(){
            if (enemy.size() == 0){return false;}
            else {return true;}
        }
        Enemy get_enemy(){return enemy[0];}
        int get_spawn_count(){return spawn_count;}

        void set_x_coor(int x){x_coordinate = x;}
        void set_y_coor(int y){y_coordinate = y;}
        void set_walkable(bool w){walkable = w;}
        void set_npc(NPC n){npc.push_back(n);}
        void set_enemy(Enemy e){enemy.push_back(e);}
        // void set_has_player(bool x){has_player = x;}
        void set_spawn_count(int s){
            spawn_count = s;
        }

        Block(int x, int y, bool w) {
            set_x_coor(x);
            set_y_coor(y);
            set_walkable(w);
            set_spawn_count(0);
        }

};

#endif