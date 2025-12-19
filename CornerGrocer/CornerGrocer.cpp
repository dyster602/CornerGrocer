#include "GroceryTracker.h"
#include <iostream>
#include <limits>

static void PrintMenu() {
    std::cout << "\n===== Corner Grocer Menu =====\n";
    std::cout << "1. Look up an item frequency\n";
    std::cout << "2. Print all item frequencies\n";
    std::cout << "3. Print histogram\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option (1-4): ";
}

int main() {
    GroceryTracker tracker;

    const std::string inputFile = "CS210_Project_Three_Input_File.txt";
    const std::string backupFile = "frequency.dat";

    // Step A: Load data
    if (!tracker.LoadFromFile(inputFile)) {
        std::cout << "Error: Could not open input file: " << inputFile << "\n";
        return 1;
    }

    // Step B: Create backup file at start (required)
    if (!tracker.WriteBackupFile(backupFile)) {
        std::cout << "Warning: Could not write backup file: " << backupFile << "\n";
    }

    int choice = 0;

    // Step C: Menu loop
    while (true) {
        PrintMenu();

        // Input validation (optional challenge)
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter 1-4.\n";
            continue;
        }

        if (choice == 1) {
            std::string item;
            std::cout << "Enter item: ";
            std::cin >> item;
            std::cout << item << " purchased "
                << tracker.GetItemFrequency(item)
                << " time(s).\n";
        }
        else if (choice == 2) {
            tracker.PrintAllFrequencies();
        }
        else if (choice == 3) {
            tracker.PrintHistogram('*');
        }
        else if (choice == 4) {
            std::cout << "Goodbye!\n";
            break;
        }
        else {
            std::cout << "Please choose 1-4.\n";
        }
    }

    return 0;
}