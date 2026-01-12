#include <iostream>
using namespace std;

class Vehicle{
public:
    void start()
    {
        cout << "The vehicle starts.\n";
    }
    virtual void move()
    {
        cout << "The vehicle moves.\n";
    }
};

class Car : public Vehicle{
public:
    virtual void move() override
    {
        cout << "The car moves.\n";
    }
};

int main()
{
    Vehicle* v1 = new Car();
    Vehicle* v2 = new Vehicle();
    v1->move();
    v2->move();
}