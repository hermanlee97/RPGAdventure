#include <iostream>
#include <string>
#include <windows.h>

// #### Entites Class ####
class Entity
{
public:
    int hp;
    int damage;
    int xp;
    int defence;
    int gold;
    int x;  // X and Y should be for all entities, plus I can't reference x and y in the player subclass with the move function
    int y;
};

class Player : public Entity
{
public:
    int move(Entity player, char inputMove)
    {
        if(inputMove == 'L')
        {
            player.x -= 1;
            return player.x;
        }
        else if(inputMove == 'R')
        {
            player.x += 1;
            return player.x;
        }
        else if(inputMove = 'U')
        {
            player.y += 1;
            return player.y;
        }
        else if(inputMove = 'D')
        {
            player.y -= 1;
            return player.y;
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