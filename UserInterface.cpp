#include <iostream>
#include <string>
#include "HistoryManager.h"
#include "ExpressionParser.h"

void showMenu() {
    std::cout << "\n=== Menu ===\n";
    std::cout << "1. Enter Expression\n";
    std::cout << "2. View History\n";
    std::cout << "3. Clear History\n";
    std::cout << "4. Exit\n";
    std::cout << "Choice: ";
}

int main() {
    HistoryManager manager;
    ExpressionParser parser;
    int choice;
    std::string input;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); //clear newline

        switch (choice) {
            case 1:
                std::cout << "Enter expression (e.g., 2 + 3): ";
                std::getline(std::cin, input);

                parser.setExpression(input);
                double result;
                result = parser.evaluateExpression();
                std::cout << "Result: " << result << std::endl;

                manager.addRecord(input + " = " + std::to_string(result));
                break;

            case 2:
                std::cout << "\nHistory:\n";
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
