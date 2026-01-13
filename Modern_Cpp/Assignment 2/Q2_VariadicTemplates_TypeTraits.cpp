#include <iostream>
using namespace std;

template <typename... Args>
auto sum(Args... args) // You canuse Args&... args to pass by reference!
{
    return (args + ...);
}

template <typename... Args>
typename enable_if<(is_integral<Args>::value && ...), int>::type
print(Args... args)
{
    cout << "Integral args" << endl;
    (cout << ... << args) << endl;
    return (args + ...) ;
}


template <typename... Args>
typename enable_if<(is_floating_point<Args>::value && ...), float>::type
print(Args... args)
{
    cout <<"Floating point args" << endl;
    (cout << " " << ... << args) << endl;
    return (args + ...);
}
int main()
{
    cout << sum(1,5.3,10.44223,44,98) << endl;
    
    print(1,2,4,5);
    print(3.5,2.1);
}