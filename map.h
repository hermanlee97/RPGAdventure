#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
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
        bool get_has_enemy(){return has_enemy;}
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
        vector<vector<Block> > content;
        
        int str_to_int(string s){
            stringstream temp(s);
            int x = 0;
            temp >> x;
            return x;
        }

        bool str_to_bool(string s){
            if (s == "true "){
                return true;
            }
            return false;
        }

        void make_map(string map_name){
            ifstream map_file(map_name);
            string line;
            int cur = 0;
            vector<Block> row;
            while (getline(map_file, line)){
                string a = line.substr(0,1);
                string b = line.substr(2,1);
                string c = line.substr(4,5);
                string d = line.substr(10,5);
                string e = line.substr(16,5);

                int x_coor = str_to_int(a);
                int y_coor = str_to_int(b);
                bool walkable = str_to_bool(c);
                bool npc = str_to_bool(d);
                bool enemy = str_to_bool(e);

                if (cur == x_coor){
                    row.push_back(Block(x_coor, y_coor, walkable, npc, enemy));
                }
                else{
                    content.push_back(row);
                    row.clear();
                    row.push_back(Block(x_coor, y_coor, walkable, npc, enemy));
                    cur += 1;
                }
            }
            content.push_back(row);
        }

        void print_map(){
            string m;
            for (int i = 0; i < content.size(); i++){
                for (int j = 0; j < content[i].size(); j++){
                    if (content[i][j].get_walkable()){
                        m.append("o ");
                        continue;
                    }
                    m.append("- ");
                }
                m.append("\n");
            }
            cout << m << endl;    
        }

};

#endif