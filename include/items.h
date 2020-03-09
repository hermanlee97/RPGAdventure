#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

// #### Items Class ####
class Item
{
private:
    std::string name;
    int cost;

public:
    virtual ~Item(){}; // virtual deconstructor for deletion

    void set_name(std::string input) { name = input; }
    void set_cost(int input) { cost = input; }
    std::string get_name() { return name; }
    int get_cost() { return cost; }

    // virtual functions for subclasses
    virtual std::string get_subclass() { return ""; };

    virtual void Consume(){};

    virtual void set_attack(int input){};
    virtual int get_attack() { return 0; };

    virtual void set_defence(int input){};
    virtual int get_defence() { return 0; };

    virtual bool get_has_upgrade() { return 0; };
    virtual void set_has_upgrade(bool input) {};
    virtual void upgrade_item() {};
};

class Consumable : public Item
{
public:
    virtual void Consume() { ; }
};

class Weapon : public Item
{
private:
    int attack;
    bool has_weapon_upgrade = 0;

public:
    virtual void set_attack(int input) { attack = input; }
    virtual int get_attack() { return attack; }
    virtual std::string get_subclass() { return "weapon"; }
    virtual bool get_has_upgrade() { return has_weapon_upgrade; }
    virtual void set_has_upgrade(bool input) { has_weapon_upgrade == input; }
    virtual void upgrade_item() { set_attack(attack*1.25); }

    // constructor
    Weapon(std::string a, int b, int c)
    {
        set_name(a);
        set_attack(b);
        set_cost(c);
    }
    Weapon()
    {
        set_name("");
        set_attack(0);
        set_cost(0);
    }
};

class Armour : public Item
{
private:
    int defence;
    bool has_armour_upgrade = 0;

public:
    virtual void set_defence(int input) { defence = input; }
    virtual int get_defence() { return defence; }
    virtual std::string get_subclass() { return "armour"; }
    virtual bool get_has_upgrade() { return has_armour_upgrade; }
    virtual void set_has_upgrade(bool input) { has_armour_upgrade == input; }
    virtual void upgrade_item(){ set_defence( defence*1.25 ); }

    // constructor
    Armour(std::string a, int b, int c)
    {
        set_name(a);
        set_defence(b);
        set_cost(c);
    }
    Armour()
    {
        set_name("");
        set_defence(0);
        set_cost(0);
    }
};

#endif