#include <iostream>
using namespace std;

class Employee{
private:
    int id;
    string name;
    double salary;
public:
    static int employeeCount;
    Employee(int id, string name, double salary)
    {
        employeeCount++;
        this->id = id;
        this->name = name;
        this->salary = salary;
    }
    int getId(void)
    {
        return id;
    }
    string getName(void)
    {
        return name;
    }
    double getSalary(void)
    {
        return salary;
    }
    void print(void)
    {
        cout << "============================\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    Employee e(1, "Jana", 50000);
    e.print();
}