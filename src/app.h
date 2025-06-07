#ifndef APP_H
#define APP_H

#include "inventory.h"

class App {
private:
    Inventory inventory;

public:
    void runApp();
    void displayMenu();
};

#endif