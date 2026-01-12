#include <iostream>

using namespace std;

int sum(int a, int b)
{
    a++, b++;
    return a+b-2;
}

int main()
{
    int a = 1;
    int b = 2;
    cout << sum(a,b) << endl;
    cout << a << endl;
    cout << b << endl;
}