#include "HistoryManager.h"
#include <iostream>

// Constructor
HistoryManager::HistoryManager() {}

// Add entry
void HistoryManager::addEntry(const std::string& entry) {
    history.push_back(entry);
}

// Return full history
std::vector<std::string> HistoryManager::getHistory() const {
    return history;
}

// Return history size
size_t HistoryManager::getHistorySize() const {
    return history.size();

// Clear history
void HistoryManager::clearHistory() {
    history.clear();
}
