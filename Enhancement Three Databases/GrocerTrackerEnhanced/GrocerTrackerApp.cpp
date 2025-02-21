#include "GrocerTracker.h"
#include <iostream>
#include <algorithm>  // Needed for transform()

//Constructor: Opens SQLite database and sets up tables
GrocerTracker::GrocerTracker(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
    }

    //Create groceries table if it doesn’t exist
    const char* sql1 = "CREATE TABLE IF NOT EXISTS groceries ("
        "item_name TEXT PRIMARY KEY, "
        "frequency INTEGER DEFAULT 1);";
    sqlite3_exec(db, sql1, 0, 0, 0);

    //Create metadata table if it doesn’t exist
    const char* sql2 = "CREATE TABLE IF NOT EXISTS metadata ("
        "key TEXT PRIMARY KEY, "
        "value TEXT);";
    sqlite3_exec(db, sql2, 0, 0, 0);
}

//Destructor: Closes SQLite database
GrocerTracker::~GrocerTracker() {
    sqlite3_close(db);
}

//Add or update an item in SQLite
void GrocerTracker::addItem(std::string item, int quantity) {
    // Convert item name to lowercase for consistency
    std::transform(item.begin(), item.end(), item.begin(), ::tolower);

    std::string sql = "INSERT INTO groceries (item_name, frequency) "
        "VALUES ('" + item + "', " + std::to_string(quantity) + ") "
        "ON CONFLICT(item_name) DO UPDATE SET frequency = frequency + " + std::to_string(quantity) + ";";

    if (sqlite3_exec(db, sql.c_str(), 0, 0, 0) == SQLITE_OK) {
        std::cout << "Added/Updated '" << item << "' by " << quantity << " in database." << std::endl;
    }
    else {
        std::cerr << "Error adding/updating item: " << sqlite3_errmsg(db) << std::endl;
    }
}

//Find frequency of an item in SQLite
void GrocerTracker::findItemFrequency(std::string item) {
    // Convert input item to lowercase
    std::transform(item.begin(), item.end(), item.begin(), ::tolower);

    std::string sql = "SELECT frequency FROM groceries WHERE item_name = '" + item + "';";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            int frequency = sqlite3_column_int(stmt, 0);
            std::cout << "Frequency of '" << item << "': " << frequency << std::endl;
        }
        else {
            std::cout << "'" << item << "' not found in the database." << std::endl;
        }
    }
    sqlite3_finalize(stmt);
}

//Print all grocery items and their frequencies
void GrocerTracker::printAllFrequencies() {
    std::string sql = "SELECT item_name, frequency FROM groceries;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        //std::cout << "Item Frequencies:\n"; Had it in case 3 in Main.cpp
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::cout << sqlite3_column_text(stmt, 0) << ": "
                << sqlite3_column_int(stmt, 1) << std::endl;
        }
    }
    sqlite3_finalize(stmt);
}

//Print histogram of item frequencies
void GrocerTracker::printHistogram() {
    std::string sql = "SELECT item_name, frequency FROM groceries;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        //std::cout << "Item Histogram:\n";
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::cout << sqlite3_column_text(stmt, 0) << ": "
                << std::string(sqlite3_column_int(stmt, 1), '*') << std::endl;
        }
    }
    sqlite3_finalize(stmt);
}

//Delete an item from SQLite
void GrocerTracker::deleteItem(std::string item) {
    // Convert input item to lowercase
    std::transform(item.begin(), item.end(), item.begin(), ::tolower);

    std::string sql = "DELETE FROM groceries WHERE item_name = '" + item + "';";

    if (sqlite3_exec(db, sql.c_str(), 0, 0, 0) == SQLITE_OK) {
        std::cout << "Deleted '" << item << "' from the database." << std::endl;
    }
    else {
        std::cerr << "Error deleting item: " << sqlite3_errmsg(db) << std::endl;
    }
}


//Check if the text file has already been imported
bool GrocerTracker::isFileImported() {
    std::string sql = "SELECT COUNT(*) FROM metadata WHERE key = 'file_imported';";
    sqlite3_stmt* stmt;
    int imported = 0;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            imported = sqlite3_column_int(stmt, 0);
        }
    }
    sqlite3_finalize(stmt);
    return imported > 0;
}

//Set the flag that the file has been imported
void GrocerTracker::setFileImported() {
    std::string sql = "INSERT INTO metadata (key, value) VALUES ('file_imported', 'true') "
        "ON CONFLICT(key) DO NOTHING;";
    sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}

//Reset the database (wipe all data)
void GrocerTracker::resetDatabase() {
    std::string sql = "DELETE FROM groceries; DELETE FROM metadata;";
    sqlite3_exec(db, sql.c_str(), 0, 0, 0);
    std::cout << "Database reset. File will be loaded again on next run.\n";
}
