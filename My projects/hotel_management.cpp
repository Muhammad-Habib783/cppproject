#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_ORDERS = 100;
const int MAX_MENU_ITEMS = 100;

struct MenuItem {
    string name;
    int price;
};

struct Order {
    string itemName;
    string quantity;
    int totalPrice;
};

Order orders[MAX_ORDERS];
int totalOrders = 0;
int totalBill = 0;

void displayMenu(MenuItem menu[], int totalItems) {
    cout << "-------------------------------------------------\n";
    cout << left << setw(5) << "No." << setw(25) << "Item" << right << setw(10) << "Price (Rs.)" << endl;
    cout << "-------------------------------------------------\n";
    for (int i = 0; i < totalItems; i++) {
        cout << left << setw(5) << i + 1 << setw(25) << menu[i].name << right << setw(10) << menu[i].price << endl;
    }
    cout << "-------------------------------------------------\n";
    cout << "Enter 0 to exit.\n";
    cout << "-------------------------------------------------\n";
}

void addOrder(MenuItem menu[], int totalItems) {
    int order, quantity;
    string option;
    do {
        while (true) {
            cout << "Enter your Order (0 to exit, 1 - " << totalItems << "): ";
            cin >> order;
            if (order == 0) return;
            if (order >= 1 && order <= totalItems) break;
            cout << "Invalid menu item. Please try again.\n";
        }
        cout << "You selected: " << menu[order - 1].name << endl;
        cout << "Enter the Quantity: ";
        cin >> quantity;
        orders[totalOrders].itemName = menu[order - 1].name;
        orders[totalOrders].quantity = to_string(quantity);
        orders[totalOrders].totalPrice = menu[order - 1].price * quantity;
        totalBill += orders[totalOrders].totalPrice;
        totalOrders++;
        cout << "Item: " << menu[order - 1].name << " = Rs. " << orders[totalOrders - 1].totalPrice << endl;
        cout << "Would you like to add more items (y/n)? ";
        cin >> option;
    } while (option == "y" || option == "Y");
}

void displayBill() {
    cout << "\tALLAH HU Hotel\n";
    cout << "\nYour Order Bill:\n";
    cout << "-------------------------------------------------\n";
    cout << left << setw(25) << "Item" << setw(10) << "Quantity" << setw(10) << "Price (Rs.)" << endl;
    cout << "-------------------------------------------------\n";
    for (int i = 0; i < totalOrders; i++) {
        cout << left << setw(25) << orders[i].itemName << setw(10) << orders[i].quantity << setw(10) << orders[i].totalPrice << endl;
    }
    cout << "-------------------------------------------------\n";
    cout << "Total Bill:                 Rs.  " << totalBill << endl << endl;
    cout << "Thank you for visiting ALLAH HU Hotel!\n" << endl;
}

void neglectItemFromBill(MenuItem menu[], int totalItems) {
    string input;
    cout << "Enter the serial number or item name to neglect: ";
    cin.ignore();
    getline(cin, input);
    bool itemFound = false;
    if (isdigit(input[0])) {
        int serialNumber = stoi(input) - 1;
        if (serialNumber >= 0 && serialNumber < totalItems) {
            for (int i = 0; i < totalOrders; i++) {
                if (orders[i].itemName == menu[serialNumber].name) {
                    totalBill -= orders[i].totalPrice;
                    for (int j = i; j < totalOrders - 1; j++) {
                        orders[j] = orders[j + 1];
                    }
                    totalOrders--;
                    itemFound = true;
                    break;
                }
            }
        } else {
            cout << "Invalid serial number.\n";
            return;
        }
    } else {
        for (int i = 0; i < totalOrders; i++) {
            if (orders[i].itemName == input) {
                totalBill -= orders[i].totalPrice;
                for (int j = i; j < totalOrders - 1; j++) {
                    orders[j] = orders[j + 1];
                }
                totalOrders--;
                itemFound = true;
                break;
            }
        }
    }
    if (itemFound) {
        cout << "Item successfully neglected from the bill.\n";
        displayBill();
    } else {
        cout << "No matching item found to neglect.\n";
    }
}

int main() {
    string choice;
    cout << "\t\t-: Welcome to ALLAH HU Hotel Management System :-" << endl;
    cout << "\t\t-------------------------------------------------\n";
    do {
        cout << "Menu: \n";
        cout << "1. Breakfast\n";
        cout << "2. Lunch\n";
        cout << "3. Dinner\n";
        cout << "4. Bill\n";
        cout << "0. Exit\n";
        cout << "Please Enter your Choice (0 - 4): ";
        cin >> choice;
        if (choice == "1") {
            MenuItem breakfastMenu[] = {
                {"Full fry Egg", 60}, {"Half fry Egg", 60}, {"Channy", 120}, {"Nihari", 200},
                {"Dahi", 80}, {"Chai", 60}, {"Paratha", 60}, {"Naan", 40}
            };
            int totalItems = 8;
            displayMenu(breakfastMenu, totalItems);
            addOrder(breakfastMenu, totalItems);
        } else if (choice == "2") {
            MenuItem lunchMenu[] = {
                {"Chicken Karahi", 900}, {"Chicken Biryani", 200}, {"Daal Mash", 200}, {"Daal Chana", 200},
                {"Shahi Dall", 200}, {"Lobiya Dall", 200}, {"Beef Qeema", 250}, {"Qourma", 250},
                {"Murgha", 200}, {"Sabzi", 200}, {"Roti", 20}
            };
            int totalItems = 11;
            displayMenu(lunchMenu, totalItems);
            addOrder(lunchMenu, totalItems);
        } else if (choice == "3") {
            MenuItem dinnerMenu[] = {
                {"Chicken Karahi", 900}, {"Chicken Biryani", 200}, {"Daal Mash", 200}, {"Daal Chana", 200},
                {"Shahi Dall", 200}, {"Lobiya Dall", 200}, {"Beef Qeema", 250}, {"Qourma", 250},
                {"Murgha", 200}, {"Sabzi", 200}, {"Kaleeja", 350}, {"Pota Kaleji", 300},
                {"Tawa Kaleeji", 350}, {"Fish", 1000}, {"Roti", 20}
            };
            int totalItems = 15;
            displayMenu(dinnerMenu, totalItems);
            addOrder(dinnerMenu, totalItems);
        } else if (choice == "4") {
            displayBill();
            string neglectChoice;
            cout << "Would you like to neglect any item from the bill? (y/n): ";
            cin >> neglectChoice;
            if (neglectChoice == "y" || neglectChoice == "Y") {
                MenuItem menu[] = {
                    {"Full fry Egg", 60}, {"Half fry Egg", 60}, {"Channy", 120}, {"Nihari", 200},
                    {"Dahi", 80}, {"Chai", 60}, {"Paratha", 60}, {"Naan", 40},
                    {"Chicken Karahi", 900}, {"Chicken Biryani", 200}, {"Daal Mash", 200}, {"Daal Chana", 200},
                    {"Shahi Dall", 200}, {"Lobiya Dall", 200}, {"Beef Qeema", 250}, {"Qourma", 250},
                    {"Murgha", 200}, {"Sabzi", 200}, {"Kaleeja", 350}, {"Pota Kaleji", 300},
                    {"Tawa Kaleeji", 350}, {"Fish", 1000}, {"Roti", 20}
                };
                int totalItems = 23;
                neglectItemFromBill(menu, totalItems);
            }
        } else if (choice == "0") {
            cout << "Exiting the program. Thank you!\n";
            break;
        } else {
            cout << "Please select a valid option (0 - 4).\n";
        }
    } while (choice != "0");
    return 0;
}