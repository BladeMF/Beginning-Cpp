#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	char option{};
	vector<int> numbers{};

	do
	{
		cout << "------------------------------------\n";
		cout << "Enter your choice: \n";
		cout << "1. Print numbers (P)\n";
		cout << "2. Add a number (A)\n";
		cout << "3. Display mean of the numbers (M)\n";
		cout << "4. Display the smallest number (S)\n";
		cout << "5. Display the largest number (L)\n";
		cout << "6. Quit (Q)\n";
		cin >> option;

		switch (option)
		{
		case 'P':
		case 'p':
		{
			cout << "\nYour numbers are: [";
			for (auto n : numbers)
				cout << n << " ";
			cout << "]" << endl;
			break;
		}
		case 'A':
		case 'a':
		{
			int number{};
			cout << "\nEnter a number: ";
			cin >> number;
			numbers.push_back(number);
			cout << number << " added." << endl;
			break;
		}
		case 'M':
		case 'm':
		{
			if(numbers.size() == 0) {
				cout << "Unable to calculate the mean - no data." << endl;
				break;
			}
			cout << "\nThe mean of the numbers is: ";
			double sum{};
			for (auto n : numbers)
				sum += n;
			cout << setprecision(2) << fixed;
			cout << sum / numbers.size() << endl;
			break;
		}
		case 'S':
		case 's':
		{
			if(numbers.size() == 0) {
				cout << "Unable to calculate the smallest number - the list is empty." << endl;
				break;
			}
			cout << "\nThe smallest number is: ";
			int min{INT_MAX};
			for (auto n : numbers)
				min = n < min ? n : min;
			cout << min << endl;
			break;
		}
		case 'L':
		case 'l':
		{
			if(numbers.size() == 0) {
				cout << "Unable to calculate the largest number - the list is empty." << endl;
				break;
			}
			cout << "\nThe largest number is: ";
			int max{INT_MIN};
			for (auto n : numbers)
				max = n > max ? n : max;
			cout << max << endl;
			break;
		}
		}
	} while (option != 'q' && option != 'Q');
	return 0;
}