#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character {
public:
    Enemy(std::string enemyName, int hp, int atk, int def);
    static Enemy generateRandomEnemy();
};

#endif
