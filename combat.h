#include "entities.h"

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