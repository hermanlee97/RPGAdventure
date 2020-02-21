#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

#include "block.h"
#include "entities.h"

using namespace std;

class Map {
    private:
        

    public:
        vector<vector<Block> > content;
        // get full map content
        vector<vector<Block> > get_content(){return content;}

        // get single block
        Block get_block(int x, int y){return get_content()[x][y];}

        // set single row
        void set_row(vector<Block> row){
            content.push_back(row);
        }
        // type converters
        int str_to_int(string s){
            stringstream temp(s);
            int x = 0;
            temp >> x;
            return x;
        }
        bool str_to_bool(string s){
            if (s == "true"){
                return true;
            }
            return false;
        }

        // splitting line by commas
        vector<string> split_by_comma(string line){
            vector<string> result;
            stringstream ss(line);
            for(int i = 0; i<5; i++){
                string entry;
                getline(ss, entry, ',');
                result.push_back(entry);
            }
            return result;
        }

        // create map through text file
        void make_map(string map_name){
            ifstream map_file(map_name.c_str());
            string line;
            int cur = 0;
            vector<Block> row;
            while (getline(map_file, line)){
                vector<string> split_string = split_by_comma(line);
                int x_coor = str_to_int(split_string[0]);
                int y_coor = str_to_int(split_string[1]);
                bool walkable = str_to_bool(split_string[2]);
                // bool npc = str_to_bool(split_string[3]);

                Block b(x_coor, y_coor, walkable);

                if (split_string[3] == "npc"){
                    b.set_npc(NPC(0,0,100,100,100,0,0));
                }

                if (split_string[4] == "weak enemy"){
                    b.set_enemy(Weak_Enemy(x_coor, y_coor));
                }

                else if (split_string[4] == "strong enemy"){
                    b.set_enemy(Strong_Enemy(x_coor, y_coor));
                }

                if (cur == x_coor){
                    row.push_back(b);
                }
                else{
                    content.push_back(row);
                    row.clear();
                    row.push_back(b);
                    cur += 1;
                }
            }
            set_row(row);
        }

        void print_map(Player p){
            string m = "\n";
            for (int i = 0; i < content.size(); i++){
                for (int j = 0; j < content[i].size(); j++){
                    if (p.get_x_coor() == i && p.get_y_coor() == j) {
                        m.append("X ");
                        continue;
                    }
                    else if (content[i][j].get_walkable()){
                        m.append("o ");
                        continue;
                    }
                    m.append("- ");
                }
                m.append("\n");
            }
            cout << m << endl;    
        }

        void print_mini_map(Player p){
            string m = "\n";
            for (int i = p.get_y_coor()-1; i <= p.get_y_coor()+1; i++){
                for (int j = p.get_x_coor()-1; j <= p.get_x_coor()+1; j++){
                    if (p.get_x_coor() == i && p.get_y_coor() == j) {
                        m.append("X ");
                        continue;
                    }
                    else if (content[i][j].get_walkable()){
                        m.append("o ");
                        continue;
                    }
                    m.append("- ");
                }
                m.append("\n");
            }
            cout << m << endl;    
        }

        Map(string map_name){
            make_map(map_name);
        }

};

#endif