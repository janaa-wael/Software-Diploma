#include <iostream>
using namespace std;

class Calculator{
public:
    int add(int a, int b)
    {
        cout << "Add 1" << endl;
        return a+b;
    }
    double add(double a, double b)
    {
        cout << "Add 2" << endl;
        return a+b;
    }
    int add(int a, int b, int c)
    {
        cout << "Add 3" << endl;
        return a+b+c;
    }
};

int main()
{
    Calculator c;
    cout << c.add(1,2) << endl;
    cout << c.add(1.1,(double)21) << endl;
    cout << c.add(1,2,3) << endl;
}