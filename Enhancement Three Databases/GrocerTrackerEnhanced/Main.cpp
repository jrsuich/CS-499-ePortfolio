#include "GrocerTracker.h"
#include <iostream>
#include <fstream>
#include <string>

// Function to load items from a text file into the database
void loadItemsFromFile(GrocerTracker& tracker, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "\nError: Could not open file " << filename << std::endl;
        return;
    }

    std::string item;
    while (getline(file, item)) {
        tracker.addItem(item, 1);
    }

    std::cout << "\nItems successfully loaded from file.\n";
}

// Function to display the interactive menu
void displayMenu() {
    std::cout << "\n============= MENU =============\n"
        << "1. Add Item\n"
        << "2. Find Item Frequency\n"
        << "3. Print All Frequencies\n"
        << "4. Print Histogram\n"
        << "5. Delete Item\n"
        << "6. Reset Database\n"
        << "7. Exit\n"
        << "================================\n"
        << "Enter your choice: ";
}

int main() {
    // Initialize the SQLite database
    GrocerTracker tracker("grocertracker.db");

    // Check if the file has already been imported
    if (!tracker.isFileImported()) {
        std::cout << "\nLoading items from file for the first time...\n";
        loadItemsFromFile(tracker, "CS210_Project_Three_Input_File.txt");
        tracker.setFileImported();
    }
    else {
        std::cout << "\nFile has already been imported. Skipping file load.\n";
    }

    // Interactive menu loop
    while (true) {
        displayMenu();

        int choice;
        std::cin >> choice;
        std::cin.ignore();  // Clear newline from buffer

        std::string item;
        switch (choice) {
        case 1:
            std::cout << "\nEnter item to add: ";
            getline(std::cin, item);

            int quantity;
            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            std::cin.ignore();  // Clear newline from input buffer

            tracker.addItem(item, quantity);
            break;

        case 2:
            std::cout << "\nEnter item to find frequency: ";
            getline(std::cin, item);
            tracker.findItemFrequency(item);
            break;

        case 3:
            std::cout << "\nItem Frequencies:\n";
            tracker.printAllFrequencies();
            break;

        case 4:
            std::cout << "\nItem Histogram:\n";
            tracker.printHistogram();
            break;

        case 5:
            std::cout << "\nEnter item to delete: ";
            getline(std::cin, item);
            tracker.deleteItem(item);
            break;

        case 6:
            std::cout << "\nResetting the database will delete all data!\n"
                << "Are you sure? (y/n): ";
            char confirm;
            std::cin >> confirm;
            std::cin.ignore();  // Clear newline
            if (confirm == 'y' || confirm == 'Y') {
                tracker.resetDatabase();
            }
            else {
                std::cout << "\nReset canceled.\n";
            }
            break;

        case 7:
            std::cout << "\nExiting program.\n";
            return 0;

        default:
            std::cout << "\nInvalid choice! Please try again.\n";
        }
    }
}
