#include <iostream>
#include <string>
using namespace std;
class Product
{
private:
    string productName;
    float price;
    int quantity;
public:
    static float overallSales;
    void input()
    {
        cout << "Product Name: ";
        cin >> productName;
        cout << "Price: ";
        cin >> price;
        cout << "Quantity Sold: ";
        cin >> quantity;
    }
    float getSales()
    {
        return price * quantity;
    }
    string getName()
    {
        return productName;
    }
    void display()
    {
        cout << productName
             << " | Sales = "
             << getSales()
             << endl;
    }
};
float Product::overallSales = 0;
class Store
{
private:
    string storeName;
    Product products[50];
    int n;
public:
    void input()
    {
        cout << "\nStore Name: ";
        cin >> storeName;
        cout << "Number of Products: ";
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cout << "\nProduct " << i+1 << endl;
            products[i].input();
        }
    }
    float calculateStoreSales()
    {
        float total = 0;
        for(int i=0;i<n;i++)
            total += products[i].getSales();
        return total;
    }
    string getStoreName()
    {
        return storeName;
    }
    int getCount()
    {
        return n;
    }
    Product getProduct(int i)
    {
        return products[i];
    }
    void display()
    {
        cout << "\nStore: "
             << storeName
             << endl;
        for(int i=0;i<n;i++)
            products[i].display();
        cout << "Store Total = "
             << calculateStoreSales()
             << endl;
    }
};
int main()
{
    int stores;
    cout << "Enter Number of Stores: ";
    cin >> stores;
    Store s[20];
    for(int i=0;i<stores;i++)
        s[i].input();
    float overall = 0;
    cout << "\n STORE REPORT \n";
    for(int i=0;i<stores;i++)
    {
        s[i].display();
        overall += s[i].calculateStoreSales();
    }
    int bestStore = 0;
    for(int i=1;i<stores;i++)
    {
        if(s[i].calculateStoreSales() >
           s[bestStore].calculateStoreSales())
        {
            bestStore = i;
        }
    }
    string bestProduct;
    float maxRevenue = -1;
    for(int i=0;i<stores;i++)
    {
        for(int j=0;j<s[i].getCount();j++)
        {
            Product p = s[i].getProduct(j);
            if(p.getSales() > maxRevenue)
            {
                maxRevenue = p.getSales();
                bestProduct = p.getName();
            }
        }
    }
    cout << "\n SUMMARY \n";
    cout << "Overall Sales = "
         << overall << endl;
    cout << "Best Store = "
         << s[bestStore].getStoreName()
         << endl;
    cout << "Best Selling Product = "
         << bestProduct
         << endl;
    return 0;
}

