// Section 15
// Challenge
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Trust_Account.h"
#include "Checking_Account.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moe", 2000});
    accounts.push_back(Account{"Curly", 5000});

    // display(accounts);
    // deposit(accounts, 1000);
    // withdraw(accounts,2000);

    // Savings

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{"Superman"});
    sav_accounts.push_back(Savings_Account{"Batman", 2000});
    sav_accounts.push_back(Savings_Account{"Wonderwoman", 5000, 5.0});

    // display(sav_accounts);
    // deposit(sav_accounts, 1000);
    // withdraw(sav_accounts, 2000);

    Trust_Account trust_account{"Trust account 1", 1000};
    cout << "Withdraw:" << (trust_account.withdraw(20) ? "Succeeded!" : "Failed!") << endl;
    cout << trust_account << endl;
    cout << "Withdraw:" << (trust_account.withdraw(200) ? "Succeeded!" : "Failed!") << endl;
    cout << trust_account << endl;
    cout << "Withdraw:" << (trust_account.withdraw(20) ? "Succeeded!" : "Failed!") << endl;
    cout << trust_account << endl;
    cout << "Withdraw:" << (trust_account.withdraw(20) ? "Succeeded!" : "Failed!") << endl;
    cout << trust_account << endl;
    cout << "Withdraw:" << (trust_account.withdraw(20) ? "Succeeded!" : "Failed!") << endl;
    cout << trust_account << endl;
    cout << "Deposit:" << (trust_account.deposit(50) ? "Succeeded!" : "Failed!") << endl;
    cout << trust_account << endl;
    cout << "Deposit:" << (trust_account.deposit(500) ? "Succeeded!" : "Failed!") << endl;
    cout << trust_account << endl;
    cout << "Deposit:" << (trust_account.deposit(5000) ? "Succeeded!" : "Failed!") << endl;
    cout << trust_account << endl;

    Checking_Account checking_account{"Checking account 1", 1000};
    cout << "Withdraw:" << (checking_account.withdraw(20)? "Succeeded!" : "Failed!") << endl;
    cout << checking_account << endl;
    cout << "Withdraw:" << (checking_account.withdraw(200)? "Succeeded!" : "Failed!") << endl;
    cout << checking_account << endl;

    return 0;
}
