#include <iostream>
#include <tuple>
#include <map>

using namespace std;

class Database{
    public:
    pair <string,int> p {"Sam",20};
};


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

    Database d;

    auto [name,age] = d.p;
    cout << "Custom Class Pair Attribute Values " << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;

}