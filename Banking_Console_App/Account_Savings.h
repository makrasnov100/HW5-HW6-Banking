#ifndef ACCOUNT_SAVINGS_H
#define ACCOUNT_SAVINGS_H

#include <sstream>
#include "Account.h"
#include "Customer_Adult.h"
#include "Customer_Senior.h"
#include "Customer_Student.h"

using std::stringstream;
using std::endl;

/**
Savings:Account - Header/Implementation
Defines the savings account properties

@author: Kostiantyn Makrasnov
*/


class Savings_Account : public Account {
private:
	/// INFORMATION
	//Account details printed out
	string toString() {
		stringstream ss;

		ss << "Savings Account - " << customer->getName() << endl;
		ss << "-|Account ID: " << account_number << endl;
		ss << "-|Balance: " << balance << endl;
		ss << "-|Last Transactions:" << endl;
		int amountShow = 0;
		transactions.size() <= 3 ? amountShow = transactions.size() : amountShow = 3;
		for (int i = 0; i < amountShow; i++)
			ss << "--|" << std::to_string(transactions.size() - i) << ". " << transactions[transactions.size() - (i+1)]->processTran() << endl;
		return ss.str();
	}

	/// ACCOUNT ACTIONS
	//Add interest added based on the type of account & customer (yearly)
	void addInterest() {

		//Get correct interest constant
		double interest = 0.0;
		if (typeid(Customer_Adult) == typeid(customer))
			interest = dynamic_cast<Customer_Adult*>(customer)->getSavingIntRate();
		else if (typeid(Customer_Senior) == typeid(customer))
			interest = dynamic_cast<Customer_Senior*>(customer)->getSavingIntRate();
		else if (typeid(Customer_Student) == typeid(customer))
			interest = dynamic_cast<Customer_Student*>(customer)->getSavingIntRate();

		//Add aquired interest to balance
		balance = balance * (1 + interest);
	}

public:
	/// CONSTRUCTOR(S)
	Savings_Account(Customer* cust, int accID) : Account(cust, accID) {}
};

#endif