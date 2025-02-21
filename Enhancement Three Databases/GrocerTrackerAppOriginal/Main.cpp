#include "GrocerTracker.h"
#include <iostream>
#include <string>

int main() {
    // Specify the input and output file names
    std::string inputFilename = "CS210_Project_Three_Input_File.txt";
    std::string outputFilename = "frequency.dat";

    // Create an instance of GrocerTracker
    GrocerTracker tracker(inputFilename, outputFilename);

    // Interactive menu
    while (true) {
        std::cout << "\nMenu:\n"
            << "1. Find Item Frequency\n"
            << "2. Print All Frequencies\n"
            << "3. Print Histogram\n"
            << "4. Exit\n"
            << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // Clears error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards the input buffer
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
            continue;
        }

        std::string item;
        switch (choice) {
        case 1:
            std::cout << "Enter the item name: ";
            std::cin >> item;
            tracker.findItemFrequency(item);
            break;
        case 2:
            tracker.printAllFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            std::cout << "Exiting program." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
        }
    }
}
