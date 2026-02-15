#include "store.h"

void Store::displayStore(Player& player) {
    std::cout << "\nWelcome to the Store!\n";
    std::cout << "Gold: " << player.getGold() << "\n";
    std::cout << "1. Health Potion (+20 HP) - 5 Gold\n";
    std::cout << "2. Attack Boost (+3 Attack) - 10 Gold\n";
    std::cout << "3. Exit Store\n";
    std::cout << "Choose an item to buy: ";

    int choice;
    std::cin >> choice;

    if (choice >= 1 && choice <= 2) {
        player.buyItem(choice);
    }
    else {
        std::cout << "Leaving the store...\n";
    }
}
