#include "HistoryManager.h"
#include <iostream>

// Constructor
HistoryManager::HistoryManager() {}

// Add entry
void HistoryManager::addEntry(const std::string& entry) {
    history.push_back(entry);
}

// Display history
void HistoryManager::displayHistory() const {
    for (const auto& item : history) {
        std::cout << item << std::endl;
    }
}

// Clear history
void HistoryManager::clearHistory() {
    history.clear();
}
