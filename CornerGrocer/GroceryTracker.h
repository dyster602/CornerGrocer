#pragma once
#include <map>
#include <string>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequency;

    static std::string Normalize(const std::string& s);

public:
    bool LoadFromFile(const std::string& inputFile);
    bool WriteBackupFile(const std::string& backupFile) const;

    int GetItemFrequency(const std::string& item) const;
    void PrintAllFrequencies() const;
    void PrintHistogram(char symbol = '*') const;
};