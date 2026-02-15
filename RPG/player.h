#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <iostream>

class Player : public Character {
private:
    int level;
    int experience;
    int gold;
    bool defending;
    int healthPotions;
    int attackBoosts;

public:
    Player(std::string playerName);
    void setDefending(bool state);
    bool isDefending() const;
    void gainExperience(int exp);
    void levelUp();
    void gainGold(int amount);
    int getGold() const;
    int getLevel() const;
    int getAttack();
    void buyItem(int choice);
    bool hasPotion() const;
    void usePotion();
};

#endif
