#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance)
  : Account(name, balance), withdrawal_count{0}
{
}

bool Trust_Account::deposit(double amount)
{
	if(amount >= bonus_threshold) {
		amount += bonus_amount;
	}
	return Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
	if(withdrawal_count >= withdrawal_count_limit)
		return false;

	// std::cout << *this << (Account::get_balance() * withdrawal_amount_limit_percent);
	if(amount >= (Account::get_balance() * withdrawal_amount_limit_percent)) 
		return false;

	bool result{Account::withdraw(amount)};
	if(!result) {
		return false;
	}
	withdrawal_count++;
	return true;
}
