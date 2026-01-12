#include <iostream>
#include <cstring>
#include <istream>
#include <string>
using namespace std;

class Book{
private:
    string title;
    double price;
public:
    Book()
    {
        title = "";
        price = 0;
    }
    Book(string title, double price)
    {
        this->title = title;
        this->price = price;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    string getTitle(void)
    {
        return title;
    }
    double getPrice(void)
    {
        return price;
    }
    void display(void)
    {
        cout << "Title = " << title << endl;
        cout << "Price = " << price << endl;
    }
};

int main()
{
    Book* ptr;
    ptr = new Book[3];
    for(int i = 0 ; i < 3 ; i++)
    {
        string title;
        double price;
        cout << "Enter Book Title " << endl;
        getline(cin, title);
        ptr[i].setTitle(title);
        cout << "Enter Book Price" << endl;
        cin >> price;
        cin.ignore();
        ptr[i].setPrice(price);
    }
    for(int i = 0 ; i < 3 ; i++)
    {
        cout << "Book " << i+1 << endl;
        cout << "Title: " << ptr[i].getTitle() << endl;
        cout << "Price: " << ptr[i].getPrice() << endl;
    }
    delete [] ptr;
}