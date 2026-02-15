#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int maxHealth;
    int attack;
    int defense;

public:
    Character(std::string charName, int hp, int atk, int def);
    std::string getName() const;
    int getHealth() const;
    int getDefense() const;
    bool isAlive() const;
    void takeDamage(int damage);
    void heal(int amount);
    int calculateDamage(int enemyDefense) const;
};

#endif
