#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Skill
{
    private:
        string name;
        string description;
        bool unlock;
        Skill* parent;
        Skill* sibling;
        Skill* child;

    public:
        string get_name(){ return name; }
        string get_description(){ return description; }
        bool get_unlock() { return unlock; }
        Skill* get_parent() { return parent; }
        Skill* get_sibling() { return sibling; }
        Skill* get_child() { return child; }

        void set_name(string n){ name = n; }
        void set_description(string d){ description = d; }
        void set_unlock(bool u){ unlock = u; }
        void set_parent(Skill* p){ parent = p; }
        void set_sibling(Skill* s){ sibling = s; }
        void set_child(Skill* c){ child = c; }
};
