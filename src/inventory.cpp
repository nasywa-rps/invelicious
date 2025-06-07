#include <iostream>
#include "inventory.h"
#include <fstream>
#include <sstream>

using namespace std;

void Inventory::addItem(const Item& item) {
    items.push_back(item);
}

void Inventory::displayItem() const {
    if (items.empty()) {
        cout << "Inventory empty.\n";
        return;
    }

    cout << "\n=== Stock List ===\n";
    for (const auto& item : items) {
        cout << "- " << item.getName() << ": " << item.getAmount() << " " << item.getUnit() << "\n";
    }
    cout << endl;
}

void Inventory::deductStock(string name, double amount) {
    for (auto& item : items) {
        if (item.getName() == name) {
            item.subtractAmount(amount);
            cout << name << "'s stock has been deducted.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

void Inventory::deleteItem(string name) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == name) {
            items.erase(it);
            cout << name << " has been deleted from the inventory.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

void Inventory::saveData(const string& path) const {
    ofstream file(path);
    for (const auto& item : items) {
        file << item.getName() << ";" << item.getUnit() << ";" << item.getAmount() << "\n";
    }
    file.close();
}

void Inventory::loadData(const string& path) {
    ifstream file(path);
    if (!file.is_open()) return;

    items.clear();
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nama, satuan, jumlahStr;
        if (getline(ss, nama, ';') && getline(ss, satuan, ';') && getline(ss, jumlahStr)) {
            double jumlah = stod(jumlahStr);
            items.emplace_back(nama, satuan, jumlah);
        }
    }
    file.close();
}