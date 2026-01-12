#include <iostream>

using namespace std;

class Car{
    int make;
    string model;
    int year;

    public:
    
    Car()
    {
        make = 0;
        model = "";
        year = 0;
    }

    Car(int make, string model, int year)
    {
        this->make = make;
        this->model = model;
        this->year = year;
    }
    void setMake(int make)
    {
        this->make = make;
    }
    void setModel(string model)
    {
        this->model = model;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    int getMake(void)
    {
        return make;
    }
    string getModel(void)
    {
        return model;
    }
    int getYear(void)
    {
        return year;
    }
    void print()
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl; 
    }
};

struct CarStruct{
    public:
    CarStruct()
    {
        make = 0;
        model = "";
        year = 0;
    }
    CarStruct(int ma, string mo, int ye)
    {
        make = ma;
        model = mo;
        year = ye;
    }
    void setMake(int make)
    {
        this->make = make;
    }
    void setModel(string model)
    {
        this->model = model;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    int getMake(void)
    {
        return make;
    }
    string getModel(void)
    {
        return model;
    }
    int getYear(void)
    {
        return year;
    }
    void print()
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl; 
    }
    private:
    int make;
    string model;
    int year;
};

int main()
{
    CarStruct cs(1,"BMW",2002);
    Car c(2,"Toyota",2013);
    cs.print();
    c.print();
}