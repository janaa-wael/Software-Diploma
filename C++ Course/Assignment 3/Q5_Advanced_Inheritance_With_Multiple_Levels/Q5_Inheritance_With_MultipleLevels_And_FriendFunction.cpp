#include <iostream>
using namespace std;

class Person{
private:
    string name;
    int age;
protected:
    string address;
public:
    Person(string name, int age, string address)
    : name(name), age(age), address(address)
    {

    }
    virtual void showDetails() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
    string getName(void) const
    {
        return name;
    }
    int getAge(void) const
    {
        return age;
    }

};

class Employee : public Person{
private:
    int employeeID;
public:
    Employee(string name, int age, string address, int employeeID)
    : Person(name,age,address) , employeeID(employeeID)
    {

    }
    void showDetails() const override
    {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Address: " << address << endl;
        cout << "Employee ID: " << employeeID << endl;
    }
    int getEmployeeID(void) const
    {
        return employeeID;
    }

};

class Manager : public Employee{
private:
    string department;
public:
    Manager(string name, int age, string address, int employeeID, string department)
    : Employee(name,age,address, employeeID) , department(department)
    {

    }
    string getDepartment(void)
    {
        return department;
    }
    void showDetails() const override
    {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Address: " << address << endl;
        cout << "Emplyee ID: " << getEmployeeID() << endl;
    }
    friend void showManagerInfo(Manager& mgr);
};

void showManagerInfo(Manager& mgr)
{
    cout << "Manager Inf:\n==================\n";
    mgr.showDetails();
    cout << "Department: " << mgr.department << endl;

}
int main()
{
    Manager m("Jana",22,"**$$",635,"Computer Engineer");
    showManagerInfo(m);
}