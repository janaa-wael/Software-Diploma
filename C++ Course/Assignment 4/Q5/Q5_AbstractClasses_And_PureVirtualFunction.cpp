#include <iostream>
using namespace std;

class Shape{
    public:
    virtual void draw() = 0;
};

class Rectangle : public Shape{
public:
    virtual void draw() override
    {
        cout << "Draw a Rectangle.\n";
    }

};

class Circle : public Shape{
public:
    virtual void draw() override
    {
        cout << "Draw a Circle.\n";
    }
};

int main()
{
    Shape* arr[3] = {new Rectangle(), new Circle(), new Rectangle()};
    arr[0]->draw();
    arr[1]->draw();
}