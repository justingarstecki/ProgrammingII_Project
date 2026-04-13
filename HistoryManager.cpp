#include "HistoryManager.h"
#include <iostream>

//Constructor
HistoryManager::HistoryManager() {}

//Add entry
void HistoryManager::addEntry(const std::string& entry) {
    historyList.push_back(entry);
}

//Return full history
std::vector<std::string> HistoryManager::getHistory() const {
    return historyList;
}

//Return history size
size_t HistoryManager::getHistorySize() const {
    return historyList.size();
}

//Clear history
void HistoryManager::clearHistory() {
    historyList.clear();
}
