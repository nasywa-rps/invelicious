#include "item.h"
using namespace std;

Item::Item(string name, string unit, double amount)
    : name(name), unit(unit), amount(amount) {}

string Item::getName() const {
    return name;
}

string Item::getUnit() const {
    return unit;
}

double Item::getAmount() const {
    return amount;
}

void Item::subtractAmount(double subtract) {
    if (subtract > amount) amount = 0;
    else amount -= subtract;
}

void Item::addAmount(double add) {
    amount += add;
}

void Item::setAmount(double newAmount) {
    amount = newAmount;
}
