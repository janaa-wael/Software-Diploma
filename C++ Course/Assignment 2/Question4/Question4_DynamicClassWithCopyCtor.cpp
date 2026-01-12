#include <iostream>

using namespace std;

class DynamicMatrix{
private:
    int rows;
    int cols;
    int** matrix;

public:
    DynamicMatrix(int r, int c) : rows(r), cols(c)
    {
        matrix = new int*[rows];
        for(int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols]{0};
        }
    }
    DynamicMatrix(DynamicMatrix& DM)
    {
        rows = DM.getRows();
        cols = DM.getCols();
        matrix = new int* [rows];
        for(int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
            for(int j = 0; j < cols; j++)
            {
                matrix[i][j] = DM.matrix[i][j];
            }
        }
        cout << "Copy Constructor called" << endl;
    }

    DynamicMatrix& operator= (const DynamicMatrix& other)
    {
        if (this == &other) {
            return *this;  // Self-assignment check
        }
    
        // First, deallocate existing memory
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    
        rows = other.getRows();
        cols = other.getCols();
        matrix = new int* [rows];
        for(int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
            for(int j = 0; j < cols; j++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
        std::cout << "Matrix deep copied (via assignment)" << std::endl;
        return *this;
    }

    int getRows(void) const
    {
        return rows;
    }
    int getCols(void) const
    {
        return cols;
    }

    ~DynamicMatrix()
    {
        for (int i = 0; i < rows; i++) 
        {
            delete[] matrix[i];  // Free each row
        }
        delete[] matrix;  // Free the row pointers
    }

    void display(void) const
    {
        cout << "Rows = " << rows << endl;
        cout << "Cols = " << cols << endl;
    }
};

int main()
{
    DynamicMatrix dm1(10, 20);
    cout << ";;;";
    DynamicMatrix dm2(30,40);
    dm2.display();
    DynamicMatrix dm3 = dm2;
    dm1 = dm3;
    dm1.display();
}