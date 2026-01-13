#include <iostream>

using namespace std;

template<typename T, typename R>
auto sum(T x, R y) -> decltype(x+y)
{
    return x+y;
}

int main()
{
    int x = 10;
    double y = 4.5;
    cout << sum(x,y) << endl;
}