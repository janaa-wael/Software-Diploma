#include <iostream>
#include <variant>

using namespace std;

using Number = variant<int, double>;

double add(const Number& a, const Number& b)
{
    return visit([](auto x, auto y) -> double {
        return static_cast<double>(x) + static_cast<double>(y);
    }, a, b);
}

double subtract(const Number& a, const Number& b)
{
    return visit([](auto x, auto y) -> double {
        return static_cast<double>(x) - static_cast<double>(y);
    }, a, b);
}

double multiply(const Number& a, const Number& b)
{
    return visit([](auto x, auto y) -> double {
        return static_cast<double>(x) * static_cast<double>(y);
    }, a, b);
}

int main()
{
    Number n1 = 10;
    Number n2 = 2.5;

    cout << "Add: " << add(n1, n2) << endl;
    cout << "Subtract: " << subtract(n1, n2) << endl;
    cout << "Multiply: " << multiply(n1, n2) << endl;
}
