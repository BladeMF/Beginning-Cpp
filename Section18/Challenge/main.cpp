#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
	// test your code here
	try
	{
		Trust_Account t{"Trust account", -200};
	}
	catch (IllegalBalanceException &e)
	{
		cerr << "Could not create trust account: " << e.what() << endl;
	}

	Savings_Account a{};
	a.deposit(1000);
	try
	{
		a.withdraw(2000);
	}
	catch (InsufficientFundsException &e)
	{
		cerr << "Could not withdraw: " << e.what() << endl;
	}

	std::cout << "Program completed successfully" << std::endl;
	return 0;
}
