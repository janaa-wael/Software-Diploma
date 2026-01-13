#include <iostream>

using namespace std;

constexpr int factorial(int n)
{
    if(n==0 || n== 1)
        return 1;
    return n * factorial(n-1);
}

int main()
{
    constexpr int size = 4;
    int arr[size]{3,4,5,6};

    for(auto a : arr)
    {
        cout << "Factorial of " << a << " is: " << factorial(a) << endl;
    }
}