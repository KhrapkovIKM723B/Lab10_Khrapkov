#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

struct Product 
{
    string name;
    int code;
    int quantity;
    float price;
};


void print_product(const Product& product)
{
    cout << "Товар: " << product.name << ", Код: " << product.code
        << ", Кількість: " << product.quantity << ", Ціна: " << product.price << " грн" << endl;
}


void sort_by_price(Product* products, int num) 
{
    sort(products, products + num, [](const Product& a, const Product& b) 
        {
        return a.price < b.price;
        });
}

int main()
{
   

    system("chcp 65001");


    int num;
    cout << "Введіть кількість товарів: ";
    cin >> num;
    cin.ignore(); 


    Product* products = new Product[num];

    for (int i = 0; i < num; i++)
    {
        cout << "Введіть назву товару: ";
        getline(cin, products[i].name); 
        cout << "Введіть код товару: ";
        cin >> products[i].code;
        cout << "Введіть кількість товару: ";
        cin >> products[i].quantity;
        cout << "Введіть ціну товару: ";
        cin >> products[i].price;
        cin.ignore();
    }

    cout << "\nВсі товари:\n";
    for (int i = 0; i < num; i++) 
    {
        print_product(products[i]);
    }

    sort_by_price(products, num);

    cout << "\nТовари відсортовані за ціною:\n";
    for (int i = 0; i < num; i++)
    {
        print_product(products[i]);
    }

    delete[] products;
    return 0;
}