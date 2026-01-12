#include <iostream>
using namespace std;

class LibraryItem{
public:
    virtual void displayInfo()
    {
        cout << "Display Info of Library Item.\n";
    }
};

class Book : public LibraryItem{
public:
    virtual void displayInfo() override
    {
        cout << "Display Info of Book.\n";
    }

    void borrow(int days)
    {
        cout << "Borrowing book for " << days << " days.\n";
    }

    void borrow(string name)
    {
        cout << "Book borrowed by " << name << endl;
    }
};

class DVD : public LibraryItem{
    public:
        virtual void displayInfo() override
        {
            cout << "Display Info of DVD.\n";
        }
};

class Magazine : public LibraryItem{
    public:
        virtual void displayInfo() override
        {
            cout << "Display Info of Magazine.\n";
        }
};

int main()
{
    LibraryItem* arr[3] = {new DVD(), new Magazine(), new Book()};
    arr[0]->displayInfo();
    arr[1]->displayInfo();
    arr[2]->displayInfo();
    (dynamic_cast<Book*>(arr[2]))->borrow(30);
    (dynamic_cast<Book*>(arr[2]))->borrow("Jana");
}