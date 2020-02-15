#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "map.h"
#include "block.h"
// #include "events.h"
using namespace std;

        // int str_to_int(string s){
        //     stringstream temp(s);
        //     int x = 0;
        //     temp >> x;
        //     return x;
        // }
        // bool str_to_bool(string s){
        //     if (s == "true"){
        //         return true;
        //     }
        //     return false;
        // }

        // // splitting line by commas
        // vector<string> split_by_comma(string line){
        //     vector<string> result;
        //     // cout << line << endl;
        //     stringstream ss(line);
        //     for(int i = 0; i<5; i++){
        //         string entry;
        //         getline(ss, entry, ',');
        //         // cout << entry << endl;
        //         result.push_back(entry);
        //         // cout << result[i] << endl;
        //     }
        //     // cout << result.size() << endl;
        //     return result;
        // }

        // // create map through text file
        // void make_map(string map_name){
        //     ifstream map_file(map_name);
        //     string line;
        //     int cur = 0;
        //     vector<Block> row;
        //     while (getline(map_file, line)){
        //         // cout << line << endl;
        //         vector<string> split_string = split_by_comma(line);
        //         cout << split_string[0] << endl;
        //         int x_coor = str_to_int(split_string[0]);
        //         int y_coor = str_to_int(split_string[1]);
        //         bool walkable = str_to_bool(split_string[2]);
        //         bool npc = str_to_bool(split_string[3]);

        //         Block b(x_coor, y_coor, walkable, npc);
        //     }
        // }

int main() {
    // Map map1("map_01");
    // map1.print_map();
    Map world_map("map_02");
    world_map.print_map();
    // options(world_map, 2, 1);
    cout << world_map.get_block(3,3).get_has_enemy() << endl;
    return 0;
}