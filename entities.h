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
};

class Player : public Entity
{
public:
    int x;
    int y;

    int receiveXP(Entity player, Entity enemy)
    {
        int pXP = player.xp;
        int eXP = enemy.xp;

        pXP += eXP;

        return pXP;
    }

    int receiveGold(Entity player, Entity enemy)
    {
        int pGold = player.gold;
        int eGold = enemy.gold;

        pGold += eGold;

        return pGold;
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