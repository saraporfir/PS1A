#include "character.h"

Character::Character(std::string charName, int hp, int atk, int def)
    : name(charName), health(hp), maxHealth(hp), attack(atk), defense(def) {}

std::string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getDefense() const {
    return defense;
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

void Character::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
}

int Character::calculateDamage(int enemyDefense) const {
    int damage = attack - enemyDefense;
    return damage > 0 ? damage : 1;
}
