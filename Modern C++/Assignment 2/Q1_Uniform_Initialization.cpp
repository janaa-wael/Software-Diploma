#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int x{4};
    int y{5};
    double z{10.45};
    cout << x << " " << y << " " << z << endl;

    vector<int>v{1,2,3,4};
    map <char,int>mp{{'a',1},{'b',2}, {'c',3}};

    cout << "Looping over Vector Contents using Range-Based Loops:"<<endl;
    for(auto c : v)
    {
        cout << c << " ";
    }
    cout << endl;

    cout << "Looping over Map Contents using Range-Based Loops:"<<endl;
    for(auto c : mp)
    {
        cout << "Key: " << c.first << ", Value: " << c.second << endl;
    }
}