#include <iostream>
using namespace std;

class Employee{
protected:
    string name;
    int age;
public:
    Employee()
    {
        name = "";
        age = 0;
    }

    Employee(string name, int age)
    : name(name), age(age)
    {
        
    }

    virtual void displayDetails()
    {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }


};

class Manager : public Employee{
private:
    string department;
public:
    Manager(string name, int age, string department)
    : Employee(name,age), department(department)
    {

    }
    void displayDetails() override
    {
        cout << "Name: " << name << "\nAge: " << age << "\nDepartment: " << department <<endl;
    }

};

class Engineer : public Employee{
private:
    string specialization;
public:
    Engineer(string name, int age, string specialization)
    : Employee(name,age), specialization(specialization)
    {

    }
    void displayDetails() override
    {
        cout << "Name: " << name << "\nAge: " << age << "\nSpecialization: " << specialization <<endl;
    }
};

int main()
{
    Engineer e("Jana",22,"Computer Engineer");
    e.displayDetails();
    Engineer e1("Mariam",21,"Hardware Engineer");
    e1.displayDetails();
    Manager m("X",30,"Digital Department");
    Employee arr[3] = {e,e1,m};
    arr[0].displayDetails();
    arr[2].displayDetails();
}