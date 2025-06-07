#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
private:
    string name;
    string unit;
    double amount;

public:
    Item(string name, string unit, double amount);
    string getName() const;
    string getUnit() const;
    double getAmount() const;
    void subtractAmount(double subtract);
    void setAmount(double newAmount);
};

#endif