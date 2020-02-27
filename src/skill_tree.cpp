#include <iostream>
#include <string>
#include <vector>

#include "skill.cpp"

using namespace std;

class Skill_Tree{
    private:
        Skill* root;
    
    public:
        Skill_Tree(){
            root = NULL;
            make_tree();
        }

        Skill* get_root() { return root; }

        // create root skill
        Skill* create_rest(Skill* prereq = NULL){
            Skill* r = new Skill;
            r->set_name("Rest");
            r->set_description("Sit down and rest. Nothing happens.");
            r->set_unlock(true);
            r->set_parent(prereq);
            r->set_sibling(NULL);
            r->set_child(NULL);
            return r;
        }

        // create layer 1 skills
        Skill* create_heal_1(Skill* prereq){
            Skill* h1 = new Skill;
            h1->set_name("Heal_1");
            h1->set_description("Heal user for 3 hp.");
            h1->set_unlock(false);
            h1->set_parent(prereq);
            h1->set_sibling(NULL);
            h1->set_child(NULL);
            return h1;
        }

        Skill* create_fireball(Skill* prereq){
            Skill* f = new Skill;
            f->set_name("Fireball");
            f->set_description("Fireball the target. Damage ignores armour.");
            f->set_unlock(false);
            f->set_parent(prereq);
            f->set_sibling(NULL);
            f->set_child(NULL);
            return f;
        }

        Skill* create_strength(Skill* prereq){
            Skill* st = new Skill;
            st->set_name("Strength");
            st->set_description("Increase attack by 2 till end of fight.");
            st->set_unlock(false);
            st->set_parent(prereq);
            st->set_sibling(NULL);
            st->set_child(NULL);
            return st;
        }

        // create layer 2 skills
        Skill* create_heal_2(Skill* prereq){
            Skill* h2 = new Skill;
            h2->set_name("Heal_2");
            h2->set_description("Heal user for 6 hp.");
            h2->set_unlock(false);
            h2->set_parent(prereq);
            h2->set_sibling(NULL);
            h2->set_child(NULL);
            return h2;
        }

        Skill* create_cleanse(Skill* prereq){
            Skill* cl = new Skill;
            cl->set_name("Cleanse");
            cl->set_description("Cleanse all negative effects.");
            cl->set_unlock(false);
            cl->set_parent(prereq);
            cl->set_sibling(NULL);
            cl->set_child(NULL);
            return cl;
        }

        Skill* create_freeze(Skill* prereq){
            Skill* fr = new Skill;
            fr->set_name("Freeze");
            fr->set_description("Freeze enemy. Reduces speed.");
            fr->set_unlock(false);
            fr->set_parent(prereq);
            fr->set_sibling(NULL);
            fr->set_child(NULL);
            return fr;
        }

        Skill* create_enrage(Skill* prereq){
            Skill* e = new Skill;
            e->set_name("Enrage");
            e->set_description("Lose armour, gain attack.");
            e->set_unlock(false);
            e->set_parent(prereq);
            e->set_sibling(NULL);
            e->set_child(NULL);
            return e;
        }

        // add skills to tree
        void add_rest(){
            root = create_rest();
        }
        void add_heal_1(){
            root->set_child(create_heal_1(root));
        }
        void add_fireball(){
            find_skill_node("Heal_1")->set_sibling(create_fireball(root));
        }
        void add_strength(){
            find_skill_node("Fireball")->set_sibling(create_strength(root));
        }
        void add_heal_2(){
            find_skill_node("Heal_1")->set_child(create_heal_2(root->get_child()));
        }
        void add_cleanse(){
            find_skill_node("Heal_2")->set_sibling(create_cleanse(root->get_child()));
        }
        void add_freeze(){
            find_skill_node("Fireball")->set_child(create_freeze(find_skill_node("Fireball")));
        }
        void add_enrage(){
            find_skill_node("Strength")->set_child(create_enrage(find_skill_node("Strength")));
        }

        Skill* find_skill_node(string name){
            Skill* cur = root;
            while(true){
                if (cur->get_name() == name){
                    return cur;
                }
                else if (cur->get_child() != NULL) {
                    cur = cur->get_child();
                    continue;
                }
                else if (cur->get_sibling() != NULL) {
                    cur = cur->get_sibling();
                    continue;
                }
                else if (cur->get_parent()->get_sibling() != NULL){
                    cur = cur->get_parent()->get_sibling();
                    continue;
                }
                else{
                    return NULL;
                }
            }
        }

        vector<string> get_unlockable_skills(string s){
            vector<string> unlockable;
            Skill* cur = find_skill_node(s);
            // check child's existence and add to vector
            if (cur->get_child() != NULL){
                cur = cur->get_child();
                unlockable.push_back(cur->get_name());
                // check sibling's existence and add to vector
                while(cur->get_sibling() != NULL){
                    cur = cur->get_sibling();
                    unlockable.push_back(cur->get_name());
                }
            }
            return unlockable;
        }

        void unlock_skill(string name){
            find_skill_node(name)->set_unlock(true);
        }

        void make_tree(){
            add_rest();
            add_heal_1();
            add_fireball();
            add_strength();
            add_heal_2();
            add_cleanse();
            add_freeze();
            add_enrage();
        }

};
