#include <iostream>
#include <variant>
using namespace std;

template <typename T>
struct Result
{
    variant<T, string> value;
    string s;
    bool is_ok()
    {
        return holds_alternative<T>(value);
    }
    bool is_error()
    { 
        return holds_alternative<string>(value);
    }
    T unwrap() const
    {
        return get<T>(value);
    }

    string error()
    {
        return get<string>(value);
    }

};

Result <int> divide(int a, int b)
{
    if(b == 0) 
        return Result<int>{string("Can't divide by zero.")};
    return Result<int>{a/b};
}

int main()
{
    Result<int> r = divide(10,0);
    if(r.is_ok())
    {
        cout << "No errors.\nValue of result = " << r.unwrap() << endl;
    }
    else
    {
        cout << r.error() << endl;
    }
}