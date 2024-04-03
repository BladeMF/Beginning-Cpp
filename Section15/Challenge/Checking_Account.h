#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

class Checking_Account : public Account
{
private:
  static constexpr double tax_rate = 1.5;
public:
  Checking_Account(std::string name, double balance);
	bool withdraw(double amount);
};

#endif