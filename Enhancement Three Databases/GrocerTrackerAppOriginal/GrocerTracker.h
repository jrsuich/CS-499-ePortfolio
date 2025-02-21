#ifndef GROCERTRACKER_H
#define GROCERTRACKER_H

#include <string>
#include <map>

class GrocerTracker {
private:
    std::map<std::string, int> itemFrequency; // Map to store item frequencies

    // Function to load items from file and populate the map
    void loadItemsFromFile(const std::string& filename);

    // Function to write the frequencies to a file
    void writeFrequencyToFile(const std::string& filename);

public:
    // Constructor
    GrocerTracker(const std::string& inputFilename, const std::string& outputFilename);

    // Function to find the frequency of a specific item
    void findItemFrequency(const std::string& item);

    // Function to print all item frequencies
    void printAllFrequencies();

    // Function to print a histogram of item frequencies
    void printHistogram();
};

#endif

