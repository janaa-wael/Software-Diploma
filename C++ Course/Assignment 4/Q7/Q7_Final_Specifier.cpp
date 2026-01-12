#include <iostream>
using namespace std;

class Person{
public:
    virtual void introduce()
    {
        cout << "Introduce Person" << endl;
    }
};

class Student : public Person{
public:
    virtual void introduce() override final
    {
        cout << "Introduce Student.\n";
    }
};

class CS_Student : public Student{
public:
    virtual void introduce() override final
    {
        cout << "Introduce Student.\n";
    }
};