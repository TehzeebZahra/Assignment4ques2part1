#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;
struct Product
{
    int id;
    string name;
    double price;
    Product(int _id, const string& _name, double _price) : id(_id), name(_name), price(_price) {}
};
void addProduct(vector<Product>& inventory, int id, const string& name, double price)
{
    auto it = find_if(inventory.begin(), inventory.end(), [id](const Product& p)
        {
            return p.id == id;
        });
    if (it == inventory.end())
    {
        Product newProduct(id, name, price);
        inventory.push_back(newProduct);
        cout << "Product added to the inventory." << endl;
    }
    else
    {
        cout << "Product with ID " << id << " already exists in the inventory." << endl;
    }
}
void removeProduct(vector<Product>& inventory, int id)
{
    inventory.erase(remove_if(inventory.begin(), inventory.end(), [id](const Product& p)
        {
            return p.id == id;
        }), inventory.end());
    cout << "Product with ID " << id << " removed from the inventory." << endl;
}
void displayInventory(const vector<Product>& inventory)
{
    cout << "Current Inventory:" << endl;
    for (const auto& product : inventory) {
        cout << "ID: " << product.id << "\tName: " << product.name << "\tPrice: $" << product.price << endl;
    }
    cout << "------------------------" << endl;
}
int main()
{
    vector<Product> inventory;
    addProduct(inventory, 1, "Laptop", 899.99);
    addProduct(inventory, 2, "Smartphone", 499.99);
    addProduct(inventory, 3, "Headphones", 79.99);
    displayInventory(inventory);
    removeProduct(inventory, 2);
    displayInventory(inventory);
    return 0;
}