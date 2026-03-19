#include "Player.h"

Player::Player(string name, int health)
    : name(name), health(health), currentWeapon("Fists", 5) {
}

string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

void Player::addItem(string item) {
    inventory.push_back(item);
    cout << item << " added to inventory.\n";
}

void Player::showInventory() const {
    cout << "Inventory:\n";

    if (inventory.empty()) {
        cout << "No items collected.\n";
    } else {
        for (const auto& item : inventory) {
            cout << "- " << item << endl;
        }
    }
}

void Player::setWeapon(const Weapon& weapon) {
    currentWeapon = weapon;
}

Weapon Player::getWeapon() const {
    return currentWeapon;
}