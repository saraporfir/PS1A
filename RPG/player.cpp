#include "player.h"

Player::Player(std::string playerName)
    : Character(playerName, 100, 10, 5), level(1), experience(0), gold(50), defending(false), healthPotions(0), attackBoosts(0) {}

void Player::setDefending(bool state) {
    defending = state;
}

bool Player::isDefending() const {
    return defending;
}

void Player::gainExperience(int exp) {
    experience += exp;
    if (experience >= level * 50) {
        levelUp();
    }
}

void Player::levelUp() {
    experience -= level * 50;
    level++;
    maxHealth += 20;
    health = maxHealth;
    attack += 5;
    defense += 2;
    std::cout << "\nYou leveled up! You are now level " << level << ".\n";
}

void Player::gainGold(int amount) {
    gold += amount;
}

int Player::getGold() const {
    return gold;
}

int Player::getLevel() const {
    return level;
}

int Player::getAttack() {
    return attack;
}

void Player::buyItem(int choice) {
    if (choice == 1 && gold >= 5) {
        healthPotions++;
        gold -= 5;
        std::cout << "You bought a Health Potion! (+20 HP on use)\n";
    }
    else if (choice == 2 && gold >= 10) {
        attackBoosts++;
        gold -= 10;
        std::cout << "You bought an Attack Boost! (+3 Attack on use)\n";
    }
    else {
        std::cout << "Not enough gold!\n";
    }
}

bool Player::hasPotion() const {
    return healthPotions > 0 || attackBoosts > 0;
}

void Player::usePotion() {
    if (!hasPotion()) {
        std::cout << "You have no potions left!\n";
        return;
    }

    int choice;
    do {
        std::cout << "Choose a potion to use:\n";
        std::cout << "1. Health Potion (+20 HP) - " << healthPotions << " available\n";
        std::cout << "2. Attack Boost (+3 Attack) - " << attackBoosts << " available\n";
        std::cout << "3. Cancel\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1 && healthPotions > 0) {
            heal(20);
            healthPotions--;
            std::cout << "You used a Health Potion! (+20 HP)\n";
            break;
        }
        else if (choice == 2 && attackBoosts > 0) {
            attack += 3;
            attackBoosts--;
            std::cout << "You used an Attack Boost! (+3 Attack)\n";
            break;
        }
        else if (choice == 3) {
            std::cout << "Potion use cancelled.\n";
            break;
        }
        else {
            std::cout << "Invalid choice or no potions left of that type. Try again.\n";
        }
    } while (true);
}
