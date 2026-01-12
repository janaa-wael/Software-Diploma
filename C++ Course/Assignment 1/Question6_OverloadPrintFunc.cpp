#include <iostream>

using namespace std;

void print(int x)
{
    cout << x << endl;
}

void print(double x)
{
    cout << x << endl;
}

void print(string x)
{
    cout << x << endl;
}

int main()
{
    int x = 10;
    double y = 10.59;
    string s = "Jana";
    print(x);
    print(y);
    print(s);
}