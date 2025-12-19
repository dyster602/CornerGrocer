#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <cctype>

std::string GroceryTracker::Normalize(const std::string& s) {
    std::string out = s;
    for (char& ch : out) {
        ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    }
    return out;
}

bool GroceryTracker::LoadFromFile(const std::string& inputFile) {
    std::ifstream inFS(inputFile);
    if (!inFS.is_open()) return false;

    std::string item;
    while (inFS >> item) {
        item = Normalize(item);
        itemFrequency[item]++;
    }
    return true;
}

bool GroceryTracker::WriteBackupFile(const std::string& backupFile) const {
    std::ofstream outFS(backupFile);
    if (!outFS.is_open()) return false;

    for (const auto& pair : itemFrequency) {
        outFS << pair.first << " " << pair.second << "\n";
    }
    return true;
}

int GroceryTracker::GetItemFrequency(const std::string& item) const {
    std::string key = Normalize(item);
    auto it = itemFrequency.find(key);
    if (it == itemFrequency.end()) return 0;
    return it->second;
}

void GroceryTracker::PrintAllFrequencies() const {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
}

void GroceryTracker::PrintHistogram(char symbol) const {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << symbol;
        }
        std::cout << "\n";
    }
}