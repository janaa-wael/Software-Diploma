#include <iostream>
using namespace std;

class DynamicArray{
    private:
    int* ptr;
    int size;
    public:
    DynamicArray()
    {

        size = 0;
    }
    DynamicArray(int size)
    {
        ptr = new int[size];
    }
    void setValue(int index, int value)
    {
        if(index >= size)
        {
            int newsize = index + 2;
            int* temp = new int[newsize];
            for(int i = 0; i < newsize; i++)
            {
                temp[i] = ptr[i];
            }
            delete [] ptr;
            ptr = temp;
            size = newsize;
        }
        ptr[index] = value;
    }
    void print()
    {
        for(int i = 0 ; i < size ; i++)
        {
            cout << ptr[i] << endl;
        }
    }

    ~DynamicArray()
    {
        cout << "Destructor of Dynamic Array called.\n";
        delete [] ptr;
    }
};

int main()
{
    DynamicArray arr(4);
    arr.setValue(0,3);
    arr.setValue(1,10);
    arr.setValue(3,23);
    arr.print();
}