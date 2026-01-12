#include <iostream>

using namespace std;

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x = 4;
    int y = 34;
    cout << x << " " << y << endl;
    cout << "After swapping : " << endl;
    swap(x, y);
    cout << x << " " << y << endl;
}