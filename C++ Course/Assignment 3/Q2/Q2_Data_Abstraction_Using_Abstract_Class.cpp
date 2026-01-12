#include <iostream>
using namespace std;

class Worker{
private:
    string name;
    int hoursWorked;
public:
    Worker()
    {
        name = "";
        hoursWorked = 0;
    }

    Worker(string name, int hoursWorked)
    : name(name), hoursWorked(hoursWorked)
    {

    }

    virtual int calculateSalary() = 0;
    int getHoursWorked(void)
    {
        return hoursWorked;
    }

    string getName(void)
    {
        return name;
    }

};

class FullTimeWorker : public Worker{
private:
    double monthlySalary;
public:
    FullTimeWorker(string name, int hoursWorked, int monthlySalary)
    : Worker(name, hoursWorked), monthlySalary(monthlySalary)
    {

    }
    int calculateSalary() override
    {
        return monthlySalary;
    }
};

class PartTimeWorker : public Worker{
    public:
    PartTimeWorker(string name, int hoursWorked)
    : Worker(name,hoursWorked)
    {

    }
        int calculateSalary() override
        {
            return getHoursWorked()*100;
        }
    };

int main()
{
    Worker* w1 = new FullTimeWorker("Jana",30,60000);
    Worker* w2 = new PartTimeWorker("Mariam", 70000);
    cout << w1->getName() << "'s Salary = " << w1->calculateSalary() << endl;
    cout << w2->getName() << "'s Salary = " << w2->calculateSalary() << endl;
}