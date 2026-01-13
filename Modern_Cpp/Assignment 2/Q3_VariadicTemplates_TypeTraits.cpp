#include <iostream>
#include <type_traits>
using namespace std;

template<typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
void print(T)
{
    cout << "Integral Type\n";
}

int main()
{
    print(1);
}
