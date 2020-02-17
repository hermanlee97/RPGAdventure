#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

// #### Items Class ####
class Item{
    private:
        string name;
        int attack;
        int defence;

        static int num_of_items;
    public:
        void set_name(string input){name = input;}
        void set_attack(int input){attack = input;}
        void set_defence(int input){defence = input;}

        string get_name(){return name;}
        int get_attack(){return attack;}
        int get_defence(){return defence;}

};

class Consumable : public Item{
    public:
        void Consume(){;}
};

class Equipment : public Item{
    public:

        // constructor
        Equipment(string a, int b, int c){
            set_name(a);
            set_attack(b);
            set_defence(c);
        }
        Equipment(){
            set_name("");
            set_attack(0);
            set_defence(0);
        }

};

// class Weapon : public Equipment{

// };

// class Armour : public Equipment{

// };

#endif