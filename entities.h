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

    int getHP(Entity player)
    {
        return player.hp;
    }

    int getXP(Entity player)
    {
        return player.xp;
    }

    int getDamage(Entity player)
    {
        return player.damage;
    }

    int getDefence(Entity player)
    {
        return player.defence;
    }

    int getGold(Entity player)
    {
        return player.gold;
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

    int getHP(Entity enemy)
    {
        return enemy.hp;
    }

    int getXP(Entity enemy)
    {
        return enemy.xp;
    }

    int getDamage(Entity enemy)
    {
        return enemy.damage;
    }

    int getDefence(Entity enemy)
    {
        return enemy.defence;
    }

    int getGold(Entity enemy)
    {
        return enemy.gold;
    }
};

class NPC : public Entity
{

    int getHP(Entity npc)
    {
        return npc.hp;
    }

    int getXP(Entity npc)
    {
        return npc.xp;
    }

    int getDamage(Entity npc)
    {
        return npc.damage;
    }

    int getDefence(Entity npc)
    {
        return npc.defence;
    }

    int getGold(Entity npc)
    {
        return npc.gold;
    }
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