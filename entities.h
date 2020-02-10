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

    int move(Entity player, char inputMove)
    {
        if(inputMove == 'L')
        {
            player.x -= 1;
        }
        else if(inputMove == 'R')
        {
            player.x += 1;
        }
        else if(inputMove = 'U')
        {
            player.y += 1;
        }
        else if(inputMove = 'D')
        {
            player.y -= 1;
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