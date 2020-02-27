#ifndef ENTITIES_H
#define ENTITIES_H

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "items.h"

#include "printingSpaces.h"

using namespace std;

// #### Entites Class ####
class Entity
{
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
    void set_x_coor(int x) { x_coor = x; }
    void set_y_coor(int y) { y_coor = y; }
    void set_max_hp(int a) { max_hp = a; }
    void set_hp(int h) { hp = h; }
    void set_damage(int b) { damage = b; }
    void set_defence(int c) { defence = c; }
    void set_gold(int d) { gold = d; }
    void set_xp(int e) { xp = e; }

    int get_x_coor() { return x_coor; }
    int get_y_coor() { return y_coor; }
    int get_max_hp() { return max_hp; }
    int get_hp() { return hp; }
    int get_damage() { return damage; }
    int get_defence() { return defence; }
    int get_gold() { return gold; }
    int get_xp() { return xp; }
};

class Player : public Entity
{
public:
    Equipment equipment;
    vector<Equipment> inventory;
    vector<Equipment> armour_slot;
    vector<Equipment> weapon_slot;

    // constructor
    Player(int x, int y, int a, int b, int c, int d, int e)
    {
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
    void move_up() { set_x_coor(get_x_coor() - 1); }
    void move_down() { set_x_coor(get_x_coor() + 1); }
    void move_left() { set_y_coor(get_y_coor() - 1); }
    void move_right() { set_y_coor(get_y_coor() + 1); }

    // win
    void win(int h, int g, int x)
    {
        set_hp(h);
        set_gold(get_gold() + g);
        set_xp(get_xp() + x);
        TextWindow(6, "You've gained " + to_string(g) + " gold\nand " + to_string(x) + " xp.");
    }

    // lose
    void lose()
    {
        set_x_coor(0);
        set_y_coor(0);
        set_hp(get_max_hp());
        if (get_gold() != 0)
        {
            set_gold(get_gold() - 1);
        }
        TextWindow(3, "You've lost 1 gold and\nwill be reborn at start location.\n");
        TextWindow(7, "Enter anything to be reborn.");
        string nothing;
        cin >> nothing;
    }

    // display
    void display_stat()
    {
        TextWindow(5, "Co-ordinates: (" + to_string(get_x_coor()) + "," + to_string(get_y_coor()) + ")" + "\nHP: " + to_string(get_hp()) + "/" + to_string(get_max_hp()) + "\nAttack: " + to_string(get_damage()) + "\nDefence: " + to_string(get_defence()) + "\nGold: " + to_string(get_gold()) + "\nXP: " + to_string(get_xp()));
    }

    // inventory

    void add_item(Equipment item)
    {
        inventory.push_back(item);
    }

    void remove_item(int element)
    {
        inventory.erase(inventory.begin() + element);
    }

    void list_inventory()
    {
        if (inventory.size() == 0)
        {
            TextWindow(4, "Inventory is empty.");
        }
        else
        {
            string allTheItems = "";
            for (int i = 0; i < inventory.size(); i++)
            {
                allTheItems += to_string(i + 1) + ". " + inventory[i].get_name() + "\n";
            }

            TextWindow(5, allTheItems);
        }
    }

    void list_armour()
    {
        string allTheItems = "";
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].get_defence() == 0)
            {
                continue;
            }
            else
            {
                allTheItems += to_string(i + 1) + ". " + inventory[i].get_name() + "\n";
            }
        }
        TextWindow(5, allTheItems);
    }

    void list_weapon()
    {
        string allTheItems = "";
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].get_attack() == 0)
            {
                continue;
            }
            else
            {
                allTheItems += to_string(i + 1) + ". " + inventory[i].get_name() + "\n";
            }
        }
        TextWindow(5, allTheItems);
    }

    // armour

    void equip_armour(int element)
    {
        armour_slot.push_back(inventory[element]);
        inventory.erase(inventory.begin() + element);
        int new_defence = get_defence() + armour_slot[0].get_defence();
        set_defence(new_defence);
    }

    void unequip_armour(int element)
    {
        int new_defence = get_defence() - armour_slot[0].get_defence();
        set_defence(new_defence);
        inventory.push_back(armour_slot[element]);
        armour_slot.erase(armour_slot.begin() + element);
    }

    // weapons

    void equip_weapon(int element)
    {
        weapon_slot.push_back(inventory[element]);
        inventory.erase(inventory.begin() + element);
        int new_damage = get_damage() + weapon_slot[0].get_attack();
        set_damage(new_damage);
    }

    void unequip_weapon(int element)
    {
        int new_damage = get_damage() - weapon_slot[0].get_attack();
        set_damage(new_damage);
        inventory.push_back(weapon_slot[element]);
        weapon_slot.erase(weapon_slot.begin() + element);
    }
};

class Enemy : public Entity
{
public:
    vector<string> loot; //change type to items when ready

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

class Weak_Enemy : public Enemy
{
public:
    Weak_Enemy(int x, int y)
    {
        set_x_coor(x);
        set_y_coor(y);
        set_hp(5);
        set_damage(1);
        set_defence(0);
        set_gold(1);
        set_xp(1);
    }
};

class Strong_Enemy : public Enemy
{
public:
    Strong_Enemy(int x, int y)
    {
        set_x_coor(x);
        set_y_coor(y);
        set_hp(20);
        set_damage(7);
        set_defence(2);
        set_gold(10);
        set_xp(10);
    }
};

class NPC : public Entity
{
public:
    Equipment equipment;
    Consumable consumable;
    vector<Equipment> equipment_vendor;
    vector<Consumable> consumable_vendor;

    // equipment

    void refresh_equipment()
    {
        ;
    }

    void list_equipment()
    {
        ;
    }

    // consumables

    void refresh_consumables()
    {
    }

    void list_consumables()
    {
        ;
    }

    // player interaction

    void buy_item(Player player)
    {
        ;
    }

    void sell_item(Player player)
    {
        ;
    }

    NPC(int x, int y, int a, int b, int c, int d, int e)
    {
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