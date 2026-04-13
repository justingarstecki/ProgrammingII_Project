#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H

#include <vector>
#include <string>

class HistoryManager {
private:
    std::vector<std::string> historyList;

public:
    HistoryManager();

    void addEntry(const std::string& entry);

    std::vector<std::string> getHistory() const;

    size_t getHistorySize() const;

    void clearHistory();
};

#endif
