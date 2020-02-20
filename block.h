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
        vector<Enemy> enemy;
        //bool has_player;
        int spawn_count;

    public:
        int get_x_coor(){return x_coordinate;}
        int get_y_coor(){return y_coordinate;}
        bool get_walkable(){return walkable;}
        bool get_has_npc(){return has_npc;}
        bool get_has_enemy(){
            if (enemy.size() == 0){return false;}
            else {return true;}
        }
        Enemy get_enemy(){
            return enemy[0];   
        }
        // bool get_has_player(){return has_player;}
        int get_spawn_count(){return spawn_count;}

        void set_x_coor(int x){x_coordinate = x;}
        void set_y_coor(int y){y_coordinate = y;}
        void set_walkable(bool w){walkable = w;}
        void set_has_npc(bool n){has_npc = n;}
        void set_enemy(Enemy e){enemy.push_back(e);}
        // void set_has_player(bool x){has_player = x;}
        void set_spawn_count(int f){
            spawn_count = f;
            cout << f << endl;
            cout << spawn_count <<endl;
            }

        Block(int x, int y, bool w, bool npc) {
            set_x_coor(x);
            set_y_coor(y);
            set_walkable(w);
            set_has_npc(npc);
            set_spawn_count(0);
        }

};

#endif