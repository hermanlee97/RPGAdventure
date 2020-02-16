#ifndef ENTITIES_H
#define ENTITIES_H

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

// #### Entites Class ####
class Entity{
    private:
        int x_coor;
        int y_coor;
        int max_hp;
        int hp;
        int damage;
        int defence;
        int gold;
        int xp;

    public:
        void set_x_coor(int x){x_coor = x;}
        void set_y_coor(int y){y_coor = y;}
        void set_max_hp(int a){max_hp = a;}
        void set_hp(int h){hp = h;}
        void set_damage(int b){damage = b;}
        void set_defence(int c){defence = c;}
        void set_gold(int d){gold = d;}
        void set_xp(int e){xp = e;}

        int get_x_coor(){return x_coor;}
        int get_y_coor(){return y_coor;}
        int get_max_hp(){return max_hp;}
        int get_hp(){return hp;}
        int get_damage(){return damage;}
        int get_defence(){return defence;}
        int get_gold(){return gold;}
        int get_xp(){return xp;}

};

class Player : public Entity{
    public:
        Equipment equipment;
        vector<Equipment> inventory;
        vector<Equipment> armour_slot;
        vector<Equipment> weapon_slot;
        
        // constructor
        Player(int x, int y, int a, int b, int c, int d, int e){
            set_x_coor(x);
            set_y_coor(y);
            set_max_hp(a);
            set_hp(a);
            set_damage(b);
            set_defence(c);
            set_gold(d);
            set_xp(e);
        }

        // movement
        void move_up(){set_x_coor(get_x_coor()-1);}
        void move_down(){set_x_coor(get_x_coor()+1);}
        void move_left(){set_y_coor(get_y_coor()-1);}
        void move_right(){set_y_coor(get_y_coor()+1);}

        // win
        void win(int h, int g, int x){
            set_hp(h);
            set_gold(get_gold()+g);
            set_xp(get_xp()+x);
            cout << "You gained " << g << " gold and " << x << " xp.\n" << endl;
        }

        // lose
        void lose(){
            set_x_coor(0);
            set_y_coor(0);
            set_hp(get_max_hp());
            if (get_gold()!=0) {
                set_gold(get_gold()-1);
            }
            cout << "You lost 1 gold and will be reborn at start location.\n" << endl;
            cout << "Enter anything to reborn." << endl;
            string nothing;
            cin >> nothing;
        }

        // display
        void display_stat() {
            cout << "\nCoordinte: (" << get_x_coor() << "," << get_y_coor() << ")" << endl;
            cout << "HP: " << get_hp() << "/" << get_max_hp() << endl;
            cout << "Attack: " << get_damage() << endl;
            cout << "Defence: " << get_defence() << endl;
            cout << "Gold: " << get_gold() << endl;
            cout << "XP: " << get_xp() << "\n" << endl;
        }

        // inventory
        void add_item(Equipment item){
            inventory.push_back(item);
        }
        
        void remove_item(int element){
            inventory.erase(inventory.begin() + element);
        }

        void equip_armour(int element){
            armour_slot.push_back(inventory[element]);
            inventory.erase(inventory.begin() + element);
        }

        void unequip_armour(int element){
            inventory.push_back(armour_slot[element]);
            armour_slot.erase(armour_slot.begin() + element);
        }

        void list_inventory(){
            for(int i; i < inventory.size(); i++){
                cout << i+1 << ". "  << inventory[i].get_name() << endl;
            }
        }
};

class Enemy : public Entity{
    public:
        vector<string> loot;    //change type to items when ready

        //  // constructor for enemy for testing
        // Enemy(int x, int y, int a, int b, int c, int d, int e){
        //     set_x_coor(x);
        //     set_y_coor(y);
        //     set_hp(a);
        //     set_damage(b);
        //     set_defence(c);
        //     set_gold(d);
        //     set_xp(e);
        // }
};

class Weak_Enemy : public Enemy{
    public:
        Weak_Enemy(int x, int y){
            set_x_coor(x);
            set_y_coor(y);
            set_hp(5);
            set_damage(1);
            set_defence(0);
            set_gold(1);
            set_xp(1);
        }
};

class Strong_Enemy : public Enemy{
    public:
        Strong_Enemy(int x, int y){
            set_x_coor(x);
            set_y_coor(y);
            set_hp(20);
            set_damage(7);
            set_defence(2);
            set_gold(10);
            set_xp(10);
        }
};

class NPC : public Entity{
    public:
        NPC(int x, int y, int a, int b, int c, int d, int e){
            set_x_coor(x);
            set_y_coor(y);
            set_hp(a);
            set_damage(b);
            set_defence(c);
            set_gold(d);
            set_xp(e);
        }
};

#endif