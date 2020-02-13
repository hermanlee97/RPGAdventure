// #include <iostream>
// #include <vector>
// #include <string>
// #include <sstream>
// #include <fstream>
// #include "map.h"
// using namespace std;

// int str_to_int(string s){
//     stringstream temp(s);
//     int x = 0;
//     temp >> x;
//     return x;
// }

// bool str_to_bool(string s){
//     if (s == "true "){
//         return true;
//     }
//     return false;
// }

// void Map::make_map(string map_name){
//     ifstream map_file(map_name);
//     string line;
//     int cur = 0;
//     vector<Block> row;
//     while (getline(map_file, line)){
//         string a = line.substr(0,1);
//         string b = line.substr(2,1);
//         string c = line.substr(4,5);
//         string d = line.substr(10,5);
//         string e = line.substr(16,5);

//         int x_coor = str_to_int(a);
//         int y_coor = str_to_int(b);
//         bool walkable = str_to_bool(c);
//         bool npc = str_to_bool(d);
//         bool enemy = str_to_bool(e);

//         if (cur == x_coor){
//             row.push_back(Block(x_coor, y_coor, walkable, npc, enemy));
//         }
//         else{
//             content.push_back(row);
//             row.clear();
//             row.push_back(Block(x_coor, y_coor, walkable, npc, enemy));
//             cur += 1;
//         }
//     }
//     content.push_back(row);
// }

// void Map::print_map(){
//     string m;
//     for (int i = 0; i < content.size(); i++){
//         for (int j = 0; j < content[i].size(); j++){
//             // bool walkable = content[i][j].get_walkable();
//             if (content[i][j].get_walkable()){
//                 m.append("o ");
//                 continue;
//             }
//             m.append("- ");
//         }
//         m.append("\n");
//     }
//     cout << m << endl;    
// }


// // int main() {
// //     Map map1;
// //     map1.make_map("map_02");
// //     map1.print_map();
// //     return 0;
// // }