#include <iostream>
#include <string>
#include "HistoryManager.h"
#include "ExpressionParser.h"
#include <exception>

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
        std::cin.ignore();

        switch (choice) {

            case 1:
                std::cout << "Enter expression (e.g., 2 + 3): ";
                std::getline(std::cin, input);

                try {
                    parser.setExpression(input);

                    double result = parser.evaluateExpression();

                    std::cout << "Result: " << result << std::endl;

                    manager.addEntry(input + " = " + std::to_string(result));
                }
                catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;

            case 2:
                std::cout << "\nHistory:\n";

                if (manager.getHistorySize() == 0) {
                    std::cout << "No history yet.\n";
                } else {
                    for (const auto& entry : manager.getHistory()) {
                        std::cout << entry << std::endl;
                    }
                }
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
