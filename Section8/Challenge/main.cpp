#include <iostream>

using namespace std;

int main()
{
	int cents{0};
	int dollars{0};
	int quarters{0};
	int dimes{0};
	int nickels{0};
	int pennies{0};

	cout << "Enter cents: ";
	cin >> cents;

	dollars = cents / 100;
	cents %= 100;
	quarters = cents / 25;
	cents %= 25;
	dimes = cents / 10;
	cents %= 10;
	nickels = cents / 5;
	cents %= 5;
	pennies = cents;

	cout << "Dollars: " << dollars << endl;
  cout << "Quarters: " << quarters << endl;
  cout << "Dimes: " << dimes << endl;
  cout << "Nickels: " << nickels << endl;
  cout << "Pennies: " << pennies << endl;
}