#include <iostream>

using namespace std;

int main()
{
	bool equals_resut{false};
	bool not_equals_resut{false};
	int num1{0}, num2{0};

	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

	equals_resut = (num1 == num2);
	not_equals_resut = (num1 != num2);

	cout << boolalpha;
	cout << "Equals: " << equals_resut << endl;
	cout << "Not equals result: " << not_equals_resut << endl;
}