#include <iostream>
using namespace std;

class Employee{
public:
    virtual void calculateSalary()
    {
        cout << "Employee calculates the salary" << endl;
    }
};  

class Manager : public Employee{
public:
    virtual void calculateSalary() override
    {
        cout << "Manager calculates the salary" << endl;
    }
};
int main()
{
    Employee* e1 = new Manager();
    Employee* e2 = new Employee();
    e1->calculateSalary();
    e2->calculateSalary();
}