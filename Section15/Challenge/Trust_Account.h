#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Account.h"

class Trust_Account : public Account
{
private:
  static constexpr int withdrawal_count_limit = 3;
  static constexpr double withdrawal_amount_limit_percent = 0.2;
  static constexpr double bonus_threshold = 5000;
  static constexpr double bonus_amount = 50;
	int withdrawal_count;

public:
  Trust_Account(std::string name, double balance);
	bool deposit(double amount);
	bool withdraw(double amount);
};

#endif