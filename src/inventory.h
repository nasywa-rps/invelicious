#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"
using namespace std;

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(const Item& item);
    void displayItem() const;
    void deductStock(string name, double amount);
    void addStock(string name, double amount);
    void deleteItem(string name);
    void saveData(const string& path) const;
    void loadData(const string& path);
    void deleteAllData();

};

#endif