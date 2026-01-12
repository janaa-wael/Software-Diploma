#include <iostream>

using namespace std;

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x = 1;
    int y = 5;
    cout << x << " " << y << endl;
    cout << "After swapping : " << endl;
    swap(&x, &y);
    cout << x << " " << y << endl;
}