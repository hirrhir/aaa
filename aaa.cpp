#include<iostream>
#include <string>
using namespace std;

const double TAX_RATE = 0.15;
const string CATEGORIES[] = {
    "Electronics", "Groceries", "Clothing",
    "Stationery", "Miscellaneous"
};

void showDetails(const string* details, float totalSales, const string& status) {
    cout << "\n******** PRODUCT REPORT ********\n";
    for(int i = 0; i < 5; i++) {
        cout << details[i] << '\n';
    }
    cout << "Total sales: $" << totalSales << '\n';
    cout << "Inventory status: " << status << '\n';
    cout << "Tax rate: " << (TAX_RATE * 100) << "%\n";
}

void showCategory(int category) {
    if(category >= 1 && category <= 5) {
        cout << "Category: " << CATEGORIES[category - 1] << '\n';
    } else {
        cout << "Invalid category!\n";
    }
}

void showSalesHistory(int soldItems, float price) {
    cout << "\nSales History:\n";
    for(int i = soldItems; i >= 1; i--) {
        cout << "Sold " << i << " @ $" << price << '\n';
    }
}

int main() {
    cout << "=== Inventory Management System ===\n";
    
    string productName;
    int category, initialStock, soldItems;
    float price;

    
    cout << "Enter product name: ";
    cin >> productName;
    
    cout << "Enter category (1-5): ";
    cin >> category;
    
    cout << "Enter initial stock: ";
    cin >> initialStock;
    
    cout << "Enter price per unit: $";
    cin >> price;
    
    cout << "Items sold: ";
    cin >> soldItems;

    
    int currentStock = initialStock - soldItems;
    float totalSales = soldItems * price;
    string stockStatus = (currentStock < 10) ? "Low" : "Good";

    
    string details[] = {
        "Product: " + productName,
        "Category ID: " + to_string(category),
        "Initial Stock: " + to_string(initialStock),
        "Current Price: $" + to_string(price),
        "Units Sold: " + to_string(soldItems)
    };

    
    showCategory(category);
    showSalesHistory(soldItems, price);
    showDetails(details, totalSales, stockStatus);

    return 0;
}