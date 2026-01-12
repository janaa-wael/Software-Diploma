#include <iostream>
#include <vector>
using namespace std;


int main()
{
    auto x = 42;
    auto v = vector<int>{5,6,7};
    auto it = v.begin();
    auto p = new string("Jana");
    auto i = new int(5);
    cout << "x: " << x << endl;
    cout << "v: ";
    for(auto n : v)
        cout << n << " ";
    cout << endl;
    cout << "it points to: " << *it << endl;
    cout << "p: " << *p << endl;
}