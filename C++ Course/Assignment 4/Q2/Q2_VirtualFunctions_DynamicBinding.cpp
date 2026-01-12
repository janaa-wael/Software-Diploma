#include <iostream>
using namespace std;

class Animal{
public:
    Animal()
    {
        cout << "Animal is created.\n";
    }
    virtual void sound()
    {
        cout << "Animal produces sound" << endl;
    }
    ~Animal()
    {
        cout << "Animal is destroyed.\n";
    }
};

class Dog : public Animal{
public:
    Dog()
    {
        cout << "Dog is created.\n";
    }

    virtual void sound() override
    {
        cout << "Dog barks.\n";
    }
    ~Dog()
    {
        cout << "Dog is destroyed.\n";
    }
};

class Cat : public Animal{
public:
    Cat()
    {
        cout << "Cat is created.\n";
    }
    virtual void sound() override
    {
        cout << "Cat meows.\n";
    }
    ~Cat()
    {
        cout << "Cat is destroyed.\n";
    }
};

int main()
{
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    Animal* a3 = new Animal();
    Cat c();
    Dog d();
    a1->sound();
    a2->sound();
    a3->sound();
}