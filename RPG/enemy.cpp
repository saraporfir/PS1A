#include "enemy.h"
#include <cstdlib>

Enemy::Enemy(std::string enemyName, int hp, int atk, int def)
    : Character(enemyName, hp, atk, def) {}

Enemy Enemy::generateRandomEnemy() {
    const std::string enemyNames[] = { "Goblin", "Orc", "Troll", "Bandit", "Wolf" };
    std::string name = enemyNames[rand() % 5];
    int hp = 50 + rand() % 50;
    int atk = 5 + rand() % 10;
    int def = 3 + rand() % 7;
    return Enemy(name, hp, atk, def);
}