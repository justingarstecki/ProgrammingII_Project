#pragma once
#include <vector>
#include <string>

class HistoryManager {
private:
    std::vector<std::string> history;

public:
    // Constructor
    HistoryManager();

    // Add entry to history
    void addEntry(const std::string& entry);

    // Get all history enteries 
    std::vector<std::string> getHistory() const;

    // Get number of enteries
    size_t getHistorySize() const;

    // Clear history
    void clearHistory();
};
