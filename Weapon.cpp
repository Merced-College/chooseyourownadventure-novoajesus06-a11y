#include "Weapon.h"

Weapon::Weapon(string name, int damage) {
    this->name = name;
    this->damage = damage;
}

string Weapon::getName() const {
    return name;
}

int Weapon::getDamage() const {
    return damage;
}