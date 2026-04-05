#include <iostream>
#include <string>
#include "HistoryManager.h"
#include "UserInterface.h"
#include "ExpressionParser.h"

void showMenu() {
    std::cout << "\n=== Menu ===\n";
    std::cout << "1. Add History Entry\n";
    std::cout << "2. View History\n";
    std::cout << "3. Clear History\n";
    std::cout << "4. Exit\n";
    std::cout << "Choice: ";
}

int main() {
    HistoryManager manager;
    int choice;
    std::string entry;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // clear newline

        switch (choice) {
            case 1:
                std::cout << "Enter entry: ";
                std::getline(std::cin, entry);
                manager.addEntry(entry);
                break;

            case 2:
                manager.displayHistory();
                break;

            case 3:
                manager.clearHistory();
                std::cout << "History cleared.\n";
                break;

            case 4:
                std::cout << "Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
