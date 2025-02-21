#include "GrocerTracker.h"
#include <fstream>
#include <iostream>

// Constructor implementation
GrocerTracker::GrocerTracker(const std::string& inputFilename, const std::string& outputFilename) {
    loadItemsFromFile(inputFilename);
    writeFrequencyToFile(outputFilename);
}

// Implement loadItemsFromFile
void GrocerTracker::loadItemsFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string item;
    while (inFile >> item) {
        itemFrequency[item]++;
    }

    inFile.close();
}

// Implement writeFrequencyToFile
void GrocerTracker::writeFrequencyToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << std::endl;
    }

    outFile.close();
}

// Implement findItemFrequency
void GrocerTracker::findItemFrequency(const std::string& item) {
    auto it = itemFrequency.find(item);
    if (it != itemFrequency.end()) {
        std::cout << "Frequency of '" << item << "': " << it->second << std::endl;
    }
    else {
        std::cout << "'" << item << "' not found in the records." << std::endl;
    }
}

// Implement printAllFrequencies
void GrocerTracker::printAllFrequencies() {
    if (itemFrequency.empty()) {
        std::cout << "No items to display." << std::endl;
        return;
    }

    std::cout << "Item Frequencies:" << std::endl;
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

// Implement printHistogram
void GrocerTracker::printHistogram() {
    if (itemFrequency.empty()) {
        std::cout << "No items to display." << std::endl;
        return;
    }

    std::cout << "Item Histogram:" << std::endl;
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << ": ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
