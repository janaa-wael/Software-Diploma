#include <iostream>
using namespace std;

int main()
{
    int** arr = new int*[3];
    for(int i = 0 ; i < 3 ; i++)
    {
        arr[i] = new int[4];
    }

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0; j < 4 ; j++)
            arr[i][j] = i*j;
    }
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            cout << arr[i][j] << endl;
        }
    }

    // Step 5: Free allocated memory
    for(int i = 0; i < 3; i++)
        delete[] arr[i];  // Free each row

    delete[] arr;  // Free the row pointers
}