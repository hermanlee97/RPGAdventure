#include "../include/combat.h"
#include <time.h> 
#include "../include/items.h"

void has_combat(Map &map, Player &player)
{
    TextWindow(2, "X:" + to_string(player.get_x_coor()) + " Y:" + to_string(player.get_y_coor()));
    if (map.get_block(player.get_x_coor(), player.get_y_coor()).get_has_enemy())
    {
        if (map.get_block(player.get_x_coor(), player.get_y_coor()).get_spawn_count() == -1 || (player.get_steps() - map.get_block(player.get_x_coor(), player.get_y_coor()).get_spawn_count()) >= 10)
        {
            combat(player, map.get_block(player.get_x_coor(), player.get_y_coor()).get_enemy());
            // if (new_hp > 0)
            // {
            //     player.win(new_hp, map.get_block(player.get_x_coor(), player.get_y_coor()).get_enemy().get_gold(), map.get_block(player.get_x_coor(), player.get_y_coor()).get_enemy().get_xp());
            //     map.update_spawn_count(player.get_x_coor(), player.get_y_coor(), player.get_steps());
            //     TextWindow(7, to_string(map.get_block(player.get_x_coor(), player.get_y_coor()).get_spawn_count()));
            // }
            // else
            // {
            //     player.lose();
            // }
        }
    }
}
    

// void combat(Player &player, Enemy enemy)
// {
//     int pHP = player.get_hp();
//     int nHP = enemy.get_hp();

//     while (nHP > 0 && pHP > 0)
//     {
//         // GIVE PLAYER CHOICE
//         // system("CLS");
//         string choice;

//         while (true)
//         {
//             TextWindow(0, "                               \n                          \n");
//             //TextWindow(0, "Enemy Appears!\n\nYour HP: " + to_string(pHP) + "\nEnemy HP: " + to_string(nHP) + "\n\n1. Fight   2. Flee ");
//                 TextWindow(0, "Enemy Appears!\n\nYour HP: " + to_string(player.get_hp()) + "\nEnemy HP: " + to_string(enemy.get_hp()) + "\n\n1. Attack   2. Use Skill \n3. Use Item  4. Run ");
//             cin >> choice;
            
//             if (choice == "1" || choice == "2")
//             {
//                 break;
//             }
//             else
//             {
//                 TextWindow(4, "Invalid input!");
//             }
//         }

//         if (choice == "1")
//         {
//             // DEAL DAMAGE TO ENEMY
//             if ((player.get_damage() - enemy.get_defence()) > 0)
//             {
//                 // system("CLS");
//                 nHP -= player.get_damage() - enemy.get_defence();
//                 TextWindow(5, "You dealt " + to_string(player.get_damage() - enemy.get_defence()) + "\ndamage to the enemy!");
//                 // system("pause");
//             }
//             else
//             {
//                 system("CLS");
//                 TextWindow(3, "The enemy deflected the blow!");
//                 // system("pause");
//             }

//             // CHECK IF THE ENEMY IS DEAD
//             if (nHP <= 0)
//             {
//                 // system("CLS");
//                 TextWindow(3, "The enemy has been defeated!");

//                 // system("pause");
//                 return pHP;
//             }
//             else
//             {
//                 // DEAL DAMAGE TO PLAYER
//                 if ((enemy.get_damage() - player.get_damage()) > 0)
//                 {
//                     // system("CLS");
//                     pHP -= enemy.get_damage() - player.get_defence();
//                     TextWindow(4, "The enemy dealt " + to_string(pHP) + " damage to you!");
//                     // system("pause");
//                 }
//                 else
//                 {
//                     // system("CLS");
//                     TextWindow(4, "You deflected the blow!");
//                     // system("pause");
//                 }
//             }

//             // CHECK IF THE PLAYER IS DEAD
//             if (pHP <= 0)
//             {
//                 TextWindow(3, "You have been defeated!");
//                 return 0;
//             }
//         }
//         else if (choice == "2")
//         {
//             // system("CLS");
//             // Since you're running take some damage. (Later loose some coins too.)
//             pHP = player.get_hp() - enemy.get_damage();
//             TextWindow(3, "The enemy managed to hit you        \nbefore you ran and dealt        \n" + to_string(enemy.get_damage()) + " damage to you!       \n");
//             // player.gold = player.gold-(player.gold/100);
//             // system("pause");
//             return pHP;
//         }

//         else
//         {
//             TextWindow(4, "Invalid input!");
//         }
//     }
//     return pHP;
// }


void combat(Player &player,Enemy enemy){
    // 1 for player turn - 0 for enemy turn
    int turn=getAttackTurn(player.get_speed(),enemy.get_speed());
    TextWindow(2,"Enemy Appears!\n\nYour HP: " + to_string(player.get_hp()) + "\nEnemy HP: " + to_string(enemy.get_hp()));
    while(player.get_hp()>0 & enemy.get_hp()>0){
        switch(turn){
            case 1:                        
                playerTurn(player,enemy);
                turn=0;
            break;
            case 2:
                enemyTurn(player,enemy);
                turn=1;
            break;
        }
        
    }    
}

void enemyTurn(Player &player,Enemy enemy){
    int dmg=(enemy.get_damage()/player.get_defence()*0.2);
    player.set_hp(player.get_hp()-dmg);
}

void playerTurn(Player &player, Enemy &enemy){
    //loop
    // display the 4 options
    // Attack use skill use items run
    //get choice 
    // attack normal function
    //use skill 
    //use items
    //run

    TextWindow(0,"1. Attack   2. Use Skill \n3. Use Item  4. Run ");
    int choice;
    while(true){
        TextWindow(0,"Enter valid command!");
        cin >> choice;
        if (choice >0 && choice <5){
            break;  
        }
                      
    }
    if(choice==1){
            //system("CLS");
            int dmg=playerAttack(player,enemy);
            enemy.set_hp(enemy.get_hp()-dmg);     
            TextWindow(0,"You have dealt enemy " + to_string(dmg));
    }else if(choice==2){
            //system("CLS");
            TextWindow(0,"Displaying available skills ");
            player.skill_in_combat();            
    }else if(choice==3){
            //system("CLS");
            TextWindow(0,"Displaying inventory");
            player.list_inventory();   
            int inv_choice;         
            while(true){
            TextWindow(0,"Enter valid command!");            
            cin>>inv_choice;
            if(inv_choice>0 && inv_choice < player.get_inventory().size())
                break;
            }
            //use inventory
            if (player.get_inventory_item(inv_choice)->get_subclass()=="armour"){
                player.unequip_armour(0);
                player.equip_armour(inv_choice-1);
            }
            else if(player.get_inventory_item(inv_choice)->get_subclass()=="weapon"){
                player.unequip_weapon(0);
                player.equip_weapon(inv_choice-1);
            }
            // use consumables
    }else if(choice==4){
        //run
        player.run(enemy.get_damage());
    }
}

int playerAttack(Player player,Enemy enemy){
    //srand(time(NULL));
    int crit= rand() % 100 + 1;
    int damage=(player.get_damage()/enemy.get_defence()*0.2);
    if(crit<=3)
        damage=damage*player.get_crit();
    return damage;
}

int getAttackTurn(int pspeed,int espeed){
    if(pspeed>=espeed)
        return 1;
    return 0;
}