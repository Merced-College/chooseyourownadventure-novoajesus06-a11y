#ifndef WEAPON_H
#define WEAPON_H

#include <string>
using namespace std;

class Weapon {
private:
    string name;
    int damage;

public:
    Weapon(string name = "Fists", int damage = 5);
    string getName() const;
    int getDamage() const;
};

#endif