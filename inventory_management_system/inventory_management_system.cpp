#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Item {
private:
    string name;
    int id;
    int quantity;
    double price;

public:
    // Constructor
    Item(string itemName, int itemId, int itemQuantity, double itemPrice)
        : name(itemName), id(itemId), quantity(itemQuantity), price(itemPrice) {}

    // Accessor methods
    int getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    // Modify item
    void updateQuantity(int newQuantity) {
        if (newQuantity >= 0) {
            quantity = newQuantity;
        } else {
            cout << "Quantity cannot be negative.\n";
        }
    }

    void updatePrice(double newPrice) {
        if (newPrice >= 0) {
            price = newPrice;
        } else {
            cout << "Price cannot be negative.\n";
        }
    }

    // Display item details
    void displayItem() const {
        cout << left << setw(10) << id
             << setw(20) << name
             << setw(10) << quantity
             << setw(10) << fixed << setprecision(2) << price
             << endl;
    }
};

class Inventory {
private:
    vector<Item> items;

    // Find item index by ID
    int findItemIndex(int id) const {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].getId() == id) {
                return i;
            }
        }
        return -1; // Not found
    }

public:
    // Add new item
    void addItem(const string& name, int id, int quantity, double price) {
        if (findItemIndex(id) == -1) {
            items.emplace_back(name, id, quantity, price);
            cout << "Item added successfully.\n";
        } else {
            cout << "Item ID already exists.\n";
        }
    }

    // Remove an item
    void removeItem(int id) {
        int index = findItemIndex(id);
        if (index != -1) {
            items.erase(items.begin() + index);
            cout << "Item removed successfully.\n";
        } else {
            cout << "Item not found.\n";
        }
    }

    // Update an item's quantity
    void updateItemQuantity(int id, int newQuantity) {
        int index = findItemIndex(id);
        if (index != -1) {
            items[index].updateQuantity(newQuantity);
            cout << "Item quantity updated successfully.\n";
        } else {
            cout << "Item not found.\n";
        }
    }

    // Update an item's price
    void updateItemPrice(int id, double newPrice) {
        int index = findItemIndex(id);
        if (index != -1) {
            items[index].updatePrice(newPrice);
            cout << "Item price updated successfully.\n";
        } else {
            cout << "Item not found.\n";
        }
    }

    // Display all items
    void displayAllItems() const {
        if (items.empty()) {
            cout << "No items in inventory.\n";
        } else {
            cout << left << setw(10) << "ID"
                 << setw(20) << "Name"
                 << setw(10) << "Quantity"
                 << setw(10) << "Price"
                 << endl;
            cout << string(50, '-') << endl;
            for (const auto& item : items) {
                item.displayItem();
            }
        }
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Update Item Quantity\n";
        cout << "4. Update Item Price\n";
        cout << "5. Display All Items\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int id, quantity;
            double price;

            cout << "Enter item name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, name);
            cout << "Enter item ID: ";
            cin >> id;
            cout << "Enter item quantity: ";
            cin >> quantity;
            cout << "Enter item price: ";
            cin >> price;

            inventory.addItem(name, id, quantity, price);
            break;
        }
        case 2: {
            int id;
            cout << "Enter item ID to remove: ";
            cin >> id;

            inventory.removeItem(id);
            break;
        }
        case 3: {
            int id, quantity;
            cout << "Enter item ID: ";
            cin >> id;
            cout << "Enter new quantity: ";
            cin >> quantity;

            inventory.updateItemQuantity(id, quantity);
            break;
        }
        case 4: {
            int id;
            double price;
            cout << "Enter item ID: ";
            cin >> id;
            cout << "Enter new price: ";
            cin >> price;

            inventory.updateItemPrice(id, price);
            break;
        }
        case 5:
            inventory.displayAllItems();
            break;
        case 0:
            cout << "Exiting the system. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
