#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // int *arr = new int[5];
    unique_ptr<int[]>p = make_unique<int[]>(5);

    // for (int i = 0; i < 5; ++i) 
    // {
    //     arr[i] = i * i;
    //     cout << arr[i] << " ";
    // }
    
    for(int i = 0; i < 5; i++)
    {
        p[i] = i+1;
    }

    for(int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

/*
// Example of Question 6: Old C++ Code
#include <iostream>
using namespace std;
int main() {
 int *arr = new int[5];
 for (int i = 0; i < 5; ++i) {
 arr[i] = i * i;
 cout << arr[i] << " ";
 }
 delete[] arr; // Manual memory management
 return 0;
}
// Refactored Modern C++ Code
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
int main() {
 vector<int> arr(5);
 for (int i = 0; i < arr.size(); ++i) {
 arr[i] = i * i;
 }
 for (auto v : arr) { // Range-based for loop
 cout << v << " ";
 }
 // Memory is managed automatically with vector
 return 0;
}
*/