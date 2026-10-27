#pragma once
#include <iostream>

using namespace std;

class Account {
private:
    static int count;
    static int nextId;
    static double totalMoney;

    char* owner;
    double balance;
    const int id;

public:
    Account(const char* owner, double balance): owner(nullptr), balance(0), id(nextId++){
        setOwner(owner);
        if (balance > 0)
            this->balance = balance;
        totalMoney += this->balance;
        count++;
        cout << "[+] Рахунок #" << id << " (" << this->owner << ")" << endl;
    }

    Account(const char* owner) : Account(owner, 0){}
    Account() : Account("Без імені", 0){}

    ~Account() {
        cout << "[-] Рахунок #" << id << " (" << owner << ")" << endl;
        totalMoney -= balance;
        count--;
        delete[] owner;
    }

    //getters
    double getBalance();
    int getId();
    static double getTotalMoney();
    static int getCount();

    //setters
    void setOwner(const char* owner);

    //other methods
    bool transfer(Account& to, double amount);
    Account& deposit(double amount);
    Account& withdraw(double amount);
    void print();
};

// inline methods
inline double Account::getBalance() 
{
    return balance;
}

inline int Account::getId() 
{
    return id;
}

inline double Account::getTotalMoney() 
{
    return totalMoney;
}

inline int Account::getCount() 
{
    return count;
}

inline void Account::print() 
{
    cout << "#" << id << " " << owner << ": " << balance << " грн" << endl;
}

