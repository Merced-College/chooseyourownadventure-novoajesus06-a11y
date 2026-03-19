#include "Enemy.h"

Enemy::Enemy(string name, int health) {
    this->name = name;
    this->health = health;
}

string Enemy::getName() const {
    return name;
}

int Enemy::getHealth() const {
    return health;
}

void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

bool Enemy::isDefeated() const {
    return health == 0;
}