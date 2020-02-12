#ifndef ENTITIES_H
#define ENTITIES_H

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// #### Entites Class ####
class Entity
{
public:
    int hp;
    int xp;
    int damage;
    int defence;
    int gold;

    int x;
    int y;
};

class Player : public Entity
{
public:
    int moveX(std::string inputMove)
    {
        if(inputMove == "L" || inputMove == "l")
        {
            x -= 1;
            return x;
        }
        else if(inputMove == "R" || inputMove == "r")
        {
            x += 1;
            return x;
        }
    }
    int moveY(std::string inputMove)
    {
        if(inputMove == "U" || inputMove == "u")
        {
            y += 1;
            return y;
        }
        else if(inputMove == "D" || inputMove == "d")
        {
            y -= 1;
            return y;
        }
    }

    Player(int a, int b, int c, int d, int e, int f)
    {
        hp = a;         // 10 for testing
        gold = b;       // 0 for testing
        damage = c;     // 5 for testing
        defence = d;    // 2 for testing

        x = e;          // 3 for testing
        y = f;          // 3 for testing
    }
};

class Enemy : public Entity
{
public:
    int x;
    int y;

    Enemy(int a, int b, int c, int d, int e)
    {
        hp = a;         // 5 for testing
        damage = b;     // 3 for testing
        defence = c;    // 1 for testing

        x = d;          // 4 for tesing
        y = e;          // 4 for testing
    }
};

class NPC : public Entity
{
};

// #### Items Class ####

class Item
{
public:
    string myname;
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
    bool isWalkable;
    bool isEnemy;
    string display;

public:
    // WALKABLE
    void setIsWalkable(bool iswalkable)
    {
        isWalkable = iswalkable;
    }

    bool getIsWalkable()
    {
        return isWalkable;
    }

    // ENEMY
    void setIsEnemy(bool isenemy)
    {
        isEnemy = isenemy;
    }

    bool getIsEnemy()
    {
        return isEnemy;
    }

    // DISPLAY
    void setDisplay(string useDisplay)
    {
        display = useDisplay;
    }

    string getDisplay()
    {
        return display;
    }
};

class Block : public Map
{
};

#endif