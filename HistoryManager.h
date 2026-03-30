#ifndef HISTORY_MANAGER_H
#define HISTORY_MANAGER_H

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

    // Display history
    void displayHistory() const;

    // Clear history
    void clearHistory();
};

#endif
