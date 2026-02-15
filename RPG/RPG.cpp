#include "player.h"
#include "enemy.h"
#include "store.h"
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

void combat(Player& player, Enemy& enemy) {
    std::cout << "\nA wild " << enemy.getName() << " appears!\n";

    while (player.isAlive() && enemy.isAlive()) {
        std::cout << "\nYour HP: " << player.getHealth() << " | "
            << "Attack: " << player.getAttack() << " | "
            << enemy.getName() << "'s HP: " << enemy.getHealth() << "\n";
        std::cout << "1. Attack\n2. Defend\n3. Use Potion\n4. Flee\nChoose your action: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            player.setDefending(false);
            int damage = player.getAttack();
            enemy.takeDamage(damage);
            std::cout << "You dealt " << damage << " damage to the " << enemy.getName() << ".\n";
        }
        else if (choice == 2) {
            player.setDefending(true);
            std::cout << "You brace yourself for the enemy's attack.\n";
            if (rand() % 2 == 0) { // 50% chance to deal counter damage
                int counterDamage = (rand() % (player.getDefense() / 2 + 1)); // Randomized lower counter damage
                if (counterDamage > 0) {
                    enemy.takeDamage(counterDamage);
                    std::cout << "Your defense countered and dealt " << counterDamage << " damage to the " << enemy.getName() << "!\n";
                }
                else {
                    std::cout << "Your counterattack missed!\n";
                }
            }
        }
        else if (choice == 3) { // Use Potion
            player.usePotion();
        }
        else if (choice == 4) {
            std::cout << "You fled from the battle!\n";
            return;
        }
        else {
            std::cout << "Invalid choice!\n";
        }

        if (!enemy.isAlive()) {
            std::cout << "\nYou have defeated " << enemy.getName() << "!\n";
            break;
        }

        if (enemy.isAlive()) {
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Delay before enemy's attack
            int damage = enemy.calculateDamage(player.getDefense());
            if (player.isDefending()) {
                damage /= 2;
            }
            player.takeDamage(damage);
            std::cout << "The " << enemy.getName() << " dealt " << damage << " damage to you!\n";
        }
    }

    if (!player.isAlive()) {
        std::cout << "\nYou have died in battle... Game Over.\n";
    }
}

int main() {
    srand(time(0));
    std::cout << "Welcome to the Text-Based RPG!\nEnter your character's name: ";
    std::string playerName;
    std::getline(std::cin, playerName);

    Player player(playerName);

    while (player.isAlive()) {
        Enemy enemy = Enemy::generateRandomEnemy();
        combat(player, enemy);

        if (!player.isAlive()) {
            std::cout << "\nGame Over!\n";
            break;
        }

        std::cout << "\nDo you want to visit the store? (1 for Yes, 0 for No): ";
        int storeChoice;
        std::cin >> storeChoice;
        if (storeChoice == 1) {
            do {
                Store::displayStore(player);
                std::cout << "\nDo you want to buy something else? (1 for Yes, 0 for No): ";
                std::cin >> storeChoice;
            } while (storeChoice == 1);
        }

        std::cout << "\nContinue exploring? (1 for Yes, 0 for No): ";
        int choice;
        std::cin >> choice;
        if (choice == 0) {
            std::cout << "\nFinal stats - Level: " << player.getLevel() << " | Gold: " << player.getGold() << "\n";
            break;
        }
    }
    return 0;
}
