#include <iostream>

using namespace std;

int f()
{
    return 10;
}

double g()
{
    return 3.14;
}


int main()
{
    decltype(f()*g()) result = f() * g();
    cout << result << endl;
}