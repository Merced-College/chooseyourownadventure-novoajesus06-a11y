#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include "Weapon.h"
using namespace std;

class Player {
private:
    string name;
    int health;
    vector<string> inventory;
    Weapon currentWeapon;

public:
    Player(string name, int health);
    string getName() const;
    int getHealth() const;
    void addItem(string item);
    void showInventory() const;
    void setWeapon(const Weapon& weapon);
    Weapon getWeapon() const;
};

#endif