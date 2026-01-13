#include <iostream>
#include <tuple>
#include <map>

using namespace std;


int main()
{
    map <string,int> mp{{"Jana",23},{"Malak",22}};
    tuple <int,char,double> t {1,'J',3.14};

    cout << "Map Contents : " << endl;
    for(auto [key,value] : mp)
    {
        cout << "Key = " << key << " , Value = " << value << endl;
    }
    cout << "Tuple Contents: " << endl;
    auto [a,b,c] = t;
    cout << "Integer = " << a << endl;
    cout << "Char = " << b << endl;
    cout << "Double = " << c << endl;
}