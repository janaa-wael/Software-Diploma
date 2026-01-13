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
    cout << "Factorial of 4 is: " << factorial(4) << endl;
    cout << "Factorial of 5 is: " << factorial(5) << endl;
    cout << "Factorial of 6 is: " << factorial(6) << endl;
}