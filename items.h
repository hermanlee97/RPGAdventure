#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

// #### Items Class ####
class Item{
    private:
        std::string name;
        int cost;
    public:
        virtual ~Item() {};   // virtual deconstructor for deletion

        void set_name(std::string input){name = input;}
        void set_cost(int input){cost = input;}
        std::string get_name(){return name;}
        int get_cost(){return cost;}

        // virtual functions for subclasses
        virtual std::string get_subclass() {};

        virtual void Consume() {};

        virtual void set_attack(int input) {};
        virtual int get_attack() {};

        virtual void set_defence(int input) {};
        virtual int get_defence() {};
};

class Consumable : public Item{
    public:
        virtual void Consume(){;}
};

class Weapon : public Item{
    private:
        int attack;
    public:
        virtual void set_attack(int input){attack = input;}
        virtual int get_attack(){return attack;}
        virtual std::string get_subclass(){return "weapon";}

    // constructor
    Weapon(std::string a, int b, int c){
        set_name(a);
        set_attack(b);
        set_cost(c);
    }
    Weapon(){
        set_name("");
        set_attack(0);
        set_cost(0);
    }
};

class Armour : public Item{
    private:
        int defence;
    public:
        virtual void set_defence(int input){defence = input;}
        virtual int get_defence(){return defence;}
        virtual std::string get_subclass(){return "armour";}

    // constructor
    Armour(std::string a, int b, int c){
        set_name(a);
        set_defence(b);
        set_cost(c);
    }
    Armour(){
        set_name("");
        set_defence(0);
        set_cost(0);
    }
};

#endif