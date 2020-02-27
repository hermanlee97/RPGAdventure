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
    int steps;

public:
    void set_x_coor(int x) { x_coor = x; }
    void set_y_coor(int y) { y_coor = y; }
    void set_max_hp(int a) { max_hp = a; }
    void set_hp(int h) { hp = h; }
    void set_damage(int b) { damage = b; }
    void set_defence(int c) { defence = c; }
    void set_gold(int d) { gold = d; }
    void set_xp(int e) { xp = e; }
    void set_steps(int f) { steps = f; }

    int get_x_coor() { return x_coor; }
    int get_y_coor() { return y_coor; }
    int get_max_hp() { return max_hp; }
    int get_hp() { return hp; }
    int get_damage() { return damage; }
    int get_defence() { return defence; }
    int get_gold() { return gold; }
    int get_xp() { return xp; }
    int get_steps() { return steps; }
};

class Player : public Entity
{
private:
    Item *item;
    Armour *armour;
    Weapon *weapon;
    std::vector<Item *> inventory;
    std::vector<Item *> armour_slot;
    std::vector<Item *> weapon_slot;

public:
    // getters
    std::vector<Item *> get_inventory() { return inventory; }
    Item *get_inventory_item(int element) { return inventory[element]; }
    std::vector<Item *> get_armour_slot() { return armour_slot; }
    std::vector<Item *> get_weapon_slot() { return weapon_slot; }
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
        set_steps(0);
    }

    // movement
    void move_up()
    {
        set_x_coor(get_x_coor() - 1);
        set_steps(get_steps() + 1);
    }
    void move_down()
    {
        set_x_coor(get_x_coor() + 1);
        set_steps(get_steps() + 1);
    }
    void move_left()
    {
        set_y_coor(get_y_coor() - 1);
        set_steps(get_steps() + 1);
    }
    void move_right()
    {
        set_y_coor(get_y_coor() + 1);
        set_steps(get_steps() + 1);
    }

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
        std::cin >> nothing;
    }

    // display
    void display_stat()
    {
        TextWindow(5, "Co-ordinates: (" + to_string(get_x_coor()) + "," + to_string(get_y_coor()) + ")" + "\nHP: " + to_string(get_hp()) + "/" + to_string(get_max_hp()) + "\nAttack: " + to_string(get_damage()) + "\nDefence: " + to_string(get_defence()) + "\nGold: " + to_string(get_gold()) + "\nXP: " + to_string(get_xp()));
    }

    // inventory
    void add_item(Item *item)
    {
        inventory.push_back(item);
    }

    void add_armour(Armour *armour)
    {
        inventory.push_back(armour);
    }

    void add_weapon(Weapon *weapon)
    {
        inventory.push_back(weapon);
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
                allTheItems += to_string(i + 1) + ". " + inventory[i]->get_name() + "\n worth " + to_string(inventory[i]->get_cost()) + " gold";
            }
            TextWindow(5, allTheItems);
        }
    }

    void list_armour()
    {
        string allTheItems = "";

        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i]->get_subclass() != "armour")
            {
                continue;
            }
            else
            {
                allTheItems += to_string(i + 1) + ". " + inventory[i]->get_name() + ", +" + to_string(inventory[i]->get_defence());
            }
        }
        TextWindow(5, allTheItems);
    }

    void list_weapon()
    {
        string allTheItems = "";

        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i]->get_subclass() != "weapon")
            {
                continue;
            }
            else
            {
                allTheItems += to_string(i + 1) + ". " + inventory[i]->get_name() + ", +" + to_string(inventory[i]->get_attack()) + "attack.";
            }
            TextWindow(5, allTheItems);
        }
    }

    // armour
    void equip_armour(int element)
    {
        armour_slot.push_back(inventory[element]);
        inventory.erase(inventory.begin() + element);
        int new_defence = get_defence() + armour_slot[0]->get_defence();
        set_defence(new_defence);
    }

    void unequip_armour(int element)
    {
        if (armour_slot.size() == 0)
        {
            TextWindow(7, "There is nothing to unequip.");
        }
        else
        {
            int new_defence = get_defence() - armour_slot[0]->get_defence();
            set_defence(new_defence);
            inventory.push_back(armour_slot[element]);
            armour_slot.erase(armour_slot.begin() + element);
        }
    }

    // weapons
    void equip_weapon(int element)
    {
        if (armour_slot.size() == 0)
        {
            TextWindow(7, "There is nothing to unequip.");
        }
        else
        {
            weapon_slot.push_back(inventory[element]);
            inventory.erase(inventory.begin() + element);
            int new_damage = get_damage() + weapon_slot[0]->get_attack();
            set_damage(new_damage);
        }
    }

    void unequip_weapon(int element)
    {
        int new_damage = get_damage() - weapon_slot[0]->get_attack();
        set_damage(new_damage);
        inventory.push_back(weapon_slot[element]);
        weapon_slot.erase(weapon_slot.begin() + element);
    }
};

class Enemy : public Entity
{
private:
    Item *item;
    vector<Item *> loot; // ready now boy
public:
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
private:
    Item *item;
    Armour *armour;
    Weapon *weapon;
    vector<Item *> vendor;

public:
    // getter
    Item *get_vendor_item(int element) { return vendor[element]; }

    // adding

    void add_armour(Armour *armour)
    {
        vendor.push_back(armour);
    }

    void add_weapon(Weapon *weapon)
    {
        vendor.push_back(weapon);
    }

    void remove_item(int element)
    {
        vendor.erase(vendor.begin() + element);
    }

    // generating equipment

    void generate_common_weapon()
    {
        int random_attack = rand() % 3 + 1;
        int cost = random_attack * 3 + 1;

        Weapon *common_weapon = new Weapon("Common Weapon", random_attack, cost);
        add_weapon(common_weapon);
    }

    void generate_rare_weapon()
    {
        int random_attack = rand() % 10 + 4;
        int cost = random_attack * 5 + 2;

        Weapon *rare_weapon = new Weapon("Rare Weapon", random_attack, cost);
        add_weapon(rare_weapon);
    }

    void generate_legendary_weapon()
    {
        int random_attack = rand() % 21 + 11;
        int cost = random_attack * 8;

        Weapon *legendary_weapon = new Weapon("Legendary Weapon", random_attack, cost);
        add_weapon(legendary_weapon);
    }

    void generate_common_armour()
    {
        int random_defence = rand() % 4 + 2;
        int cost = random_defence * 3;

        Armour *common_armour = new Armour("Common Armour", random_defence, cost);
        add_armour(common_armour);
    }

    void generate_rare_armour()
    {
        int random_defence = rand() % 8 + 5;
        int cost = random_defence * 4;

        Armour *rare_armour = new Armour("Rare Armour", random_defence, cost);
        add_armour(rare_armour);
    }

    void generate_legendary_armour()
    {
        int random_defence = rand() % 12 + 9;
        int cost = random_defence * 5;

        Armour *legendary_armour = new Armour("Legendary Armour", random_defence, cost);
        add_armour(legendary_armour);
    }

    // equipment

    void refresh_equipment()
    {
        for (int i = 0; i < 10; i++)
        {
            int vendor_dice_roll = rand() % 200 + 1;

            if (vendor_dice_roll <= 50)
            {
                generate_common_armour();
            }
            else if (vendor_dice_roll > 51 && vendor_dice_roll <= 75)
            {
                generate_rare_armour();
            }
            else if (vendor_dice_roll > 76 && vendor_dice_roll <= 100)
            {
                generate_legendary_armour();
            }
            else if (vendor_dice_roll > 101 && vendor_dice_roll <= 150)
            {
                generate_common_weapon();
            }
            else if (vendor_dice_roll > 151 && vendor_dice_roll <= 175)
            {
                generate_rare_weapon();
            }
            else if (vendor_dice_roll > 176 && vendor_dice_roll <= 200)
            {
                generate_legendary_weapon();
            }
        }
    }

    void list_equipment()
    {
        string allTheItems = "";

        if (vendor.size() == 0)
        {
            TextWindow(4, "Shop is empty.");
        }
        else
        {
            for (int i = 0; i < vendor.size(); i++)
            {
                allTheItems += to_string(i + 1) + ". " + vendor[i]->get_name() + ", costs" + to_string(vendor[i]->get_cost()) + " gold.";
            }
        }
        TextWindow(5, allTheItems);
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