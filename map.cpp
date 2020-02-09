#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "map.h"
using namespace std;

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

void Map::make_map(string map_name){
    ifstream map_file(map_name);
    string line;
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

        content.push_back(Block(x_coor, y_coor, walkable, npc, enemy));

    }
}

void Map::print_map(){
    int counter=0;
    string m;
    for (int i = 0; i < content.size(); i++)
    {
        // Block temp = content[i];
        int x = content[i].get_x_coor();
        int y = content[i].get_y_coor();
        bool walkable = content[i].get_walkable();

        if(walkable){
            m.append("o ");
            continue;
        }else{
            if(x==counter){
                m.append("x ");
            }else{
                m.append("\n");
                m.append("x ");
                counter++;
            }
        }

    }
    cout << m << endl;
    
}


int main() {
    Map map1;
    map1.make_map("map_02");
    map1.print_map();
    return 0;
}