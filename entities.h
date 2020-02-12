#ifndef ENTITIES_H
#define ENTITIES_H

#include <iostream>
#include <string>
#include <windows.h>

// #### Entites Class ####
class Entity
{
public:
    int hp;
    int xp;
    int damage;
    int defence;
    int gold;
};

class Player : public Entity
{
public:
    int x;
    int y;

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int move(std::string inputMove)
    {
        if(inputMove == "L")
        {
            x -= 1;
            return x;
        }
        else if(inputMove == "R")
        {
            x += 1;
            return x;
        }
        else if(inputMove == "U")
        {
            y += 1;
            return y;
        }
        else if(inputMove == "D")
        {
            y -= 1;
            return y;
        }
    }
};

class Enemy : public Entity
{
};

class NPC : public Entity
{
};

// #### Items Class ####

class Item
{
public:
    std::string myname;
};

class Consumable : public Item
{
public:
    int Consume()
    {
        return 0;
    }
};

class Equipment : public Item
{
public:
    void equip()
    {
    }

    void unequip()
    {
    }
};

// #### MAP ####
class Map
{
public:
};

#endif