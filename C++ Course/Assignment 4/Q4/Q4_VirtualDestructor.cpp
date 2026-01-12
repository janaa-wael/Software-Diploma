#include <iostream>
using namespace std;

class Shape{
public:
    Shape()
    {
        cout << "Shape is created.\n";
    }
    ~Shape()
    {
        cout << "Shape is destroyed.\n";
    }
};

class Circle : public Shape{
public:
    Circle()
    {
        cout << "Circle is created.\n";
    }
    ~Circle()
    {
        cout << "Circle is destroyed" << endl;
    }
};

int main()
{
    Shape* ptr = new Circle();
    delete ptr;
}