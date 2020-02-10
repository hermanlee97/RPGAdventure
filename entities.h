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
    int x;      // What's the point of these variables?
    int y;

    int combat(Entity player, Entity enemy)
    {
        int pHP = player.hp;
        int nHP = enemy.hp;

        while (nHP > 0 && pHP > 0)
        {

            // DEAL DAMAGE TO ENEMY
            if ((enemy.defence - player.damage) < 0)
            {
                nHP += enemy.defence - player.damage;
            }
            else
            {
                nHP -= 0;
            }

            // CHECK IF THE ENEMY IS DEAD
            if (nHP <= 0)
            {
                return pHP;
            }
            else
            {
                // DEAL DAMAGE TO PLAYER
                if ((player.defence - enemy.damage) < 0)
                {
                    pHP += player.defence - enemy.damage;
                }
                else
                {
                    pHP -= 0;
                }
            }

            // CHECK IF THE PLAYER IS DEAD
            if (pHP <= 0)
            {
                // Death function, END GAME LOOP
                return 0;
            }
        }

        return pHP;
    }

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