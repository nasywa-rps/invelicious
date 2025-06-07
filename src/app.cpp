#include <iostream>
#include <limits>
#include "app.h"
using namespace std;

void App::displayMenu() {
    cout << "===== Restaurant Inventory =====\n";
    cout << "1. Add item\n";
    cout << "2. View stock list\n";
    cout << "3. Report usage\n";
    cout << "4. Delete item\n";
    cout << "5. Add stock to an existing item\n";
    cout << "6. Exit\n";
    cout << "What do you want to do: ";
}

void App::runApp() {
    int opt;

    do {
        inventory.loadData("data.txt");
        displayMenu();
        cin >> opt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opt) {
            case 1: {
                string name, unit;
                double amount;

                cout << "Input item name: ";
                getline(cin, name);
                cout << "Choose the unit (kg, liter, pack(s), pcs): ";
                getline(cin, unit);
                cout << "Amount: ";
                cin >> amount;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Item item(name, unit, amount);
                inventory.addItem(item);
                inventory.saveData("data.txt");
                break;
            }
            case 2:
                inventory.displayItem();
                break;

            case 3: {
                string name;
                double amount;

                cout << "Input the used item: ";
                getline(cin, name);
                cout << "Amount used: ";
                cin >> amount;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                inventory.deductStock(name, amount);
                inventory.saveData("data.txt");
                break;
            }

            case 4: {
                string name;
                cout << "Input the item that will be deleted: ";
                getline(cin, name);
                inventory.deleteItem(name);
                inventory.saveData("data.txt");
                break;
            }

            case 5: {
                string name;
                double amount;

                cout << "Input the item that you want to add: ";
                getline(cin, name);
                cout << "Amount added: ";
                cin >> amount;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                inventory.addStock(name, amount);
                inventory.saveData("data.txt");
                break;
            }

            case 6:
                cout << "Thank you for using Invelicious!\n";
                break;
                
            default:
                cout << "Input not valid.\n";
        }

        cout << endl;

    } while (opt != 6);
}