#include <iostream>
// #include "skill.cpp"
// #include "skill_tree.cpp"
// #include "skill_tree_v2.cpp"
#include "entities.h"

using namespace std;

int main() {
    cout << "testing\n" << endl;

    Skill_Tree st;
    Player player(0, 0, 10, 5, 2, 1000, 0, st);
    player.set_skill_point(2);
    player.add_skill("Fireball");
    player.add_skill("Heal_1");
    player.set_hp(9);
    // player.learn_skill();
    player.skill_in_combat();
    player.get_hp();

    cout << "\nfinished testing" << endl;

    return 0;
}