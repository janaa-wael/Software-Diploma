#include <iostream>
using namespace std;

void print_arr(const int* ptr, int size)
{
    for(int i = 0 ; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
}

int main()
{
    int arr[] = {1,2,3};
    print_arr(arr, 3);
}