#ifndef GROCERTRACKER_H
#define GROCERTRACKER_H

#include <sqlite3.h>
#include <string>

class GrocerTracker {
private:
    sqlite3* db;

public:
    GrocerTracker(const std::string& dbName);
    ~GrocerTracker();

    void addItem(std::string item, int quantity);
    void findItemFrequency(std::string item);
    void printAllFrequencies();
    void printHistogram();
    void deleteItem(std::string item);

    bool isFileImported();
    void setFileImported();
    void resetDatabase();
};

#endif
