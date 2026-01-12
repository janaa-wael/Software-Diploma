#include <iostream>
using namespace std;

class BankAccount{
private:
    int balance;
    int accountNumber;
public:
    BankAccount()
    {
        balance = 0;
        accountNumber = 0;
    }
    BankAccount(int balance, int accountNumber)
    {
        this->balance = balance;
        this->accountNumber = accountNumber;
    }

    BankAccount& deposit(int amount)
    {
        balance += amount;
    }

    BankAccount& withdraw(int amount)
    {
        balance -= amount;
    }

    int getBalance(void)
    {
        return balance;
    }

    int getAccountNumber(void)
    {
        return accountNumber;
    }

    void setBalance(int balance)
    {
        this->balance = balance;
    }

    void setAccountNumber(int accountNumber)
    {
        this->accountNumber = accountNumber;
    }

};

class Customer{
private: 
    string name;
    int age;
public:
    Customer()
    {
        name = "";
        age = 0;
    }
    Customer(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge(void)
    {
        return age;
    }
    string getName(void)
    {
        return name;
    }
};

int main()
{
    Customer c;
    BankAccount b(100, 1);
    b.deposit(1000).withdraw(20);
    b.deposit(300);
    cout << "Amount: " << b.getBalance() << endl;
    cout << "Account Number: " << b.getAccountNumber() << endl;
}