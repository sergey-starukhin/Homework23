#include <iostream>
#include <cstring>
#include "Account.h"

using namespace std;

bool Account::transfer(Account& to, double amount) {
	if (this == &to)
	{
		cout << "Відмова: переказ самому собі" << endl;
		return false;
	}

	if (amount < 0 || amount > balance)
	{
		cout << "Відмова: некоректна сума" << endl;
		return false;
	}

	balance -= amount;
	to.balance += amount;
	return true;
}

Account& Account::deposit(double amount) {
	if (amount > 0)
	{
		balance += amount;
		totalMoney += amount;
	}
	return *this;
}

Account& Account::withdraw(double amount) {
	if (amount < 0 || amount > balance)
		cout << "Відмова : недостатньо коштів" << endl;
	else
	{
		balance -= amount;
		totalMoney -= amount;
	}
	return *this;
}

void Account::setOwner(const char* owner) {
	delete[] this->owner;
	size_t length = strlen(owner) + 1;
	this->owner = new char[length];
	strcpy_s(this->owner, length, owner);
}

