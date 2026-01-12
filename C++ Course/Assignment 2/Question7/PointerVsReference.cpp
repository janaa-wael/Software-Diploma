#include <iostream>
using namespace std;

void modifyWithPointer(int* ptr)
{
    (*ptr) += 10;
}

void modifyWithReference(int& x)
{
    x += 20;
}


int main()
{
    int num = 50;
    modifyWithPointer(&num);
    cout << "num = " << num << endl;
    modifyWithReference(num);
    cout << "num = " << num << endl;
}