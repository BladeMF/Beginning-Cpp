#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

char display_menu();
void print_numbers(const vector<int> numbers);
void add_number(vector<int> &numbers);
void calculate_mean(const vector<int> numbers);
void calculate_smallest_number(const vector<int> numbers);
void calculate_largest_number(const vector<int> numbers);

int main()
{
	char selected_option{};
	vector<int> numbers{};

	do
	{
		selected_option = display_menu();

		switch (selected_option)
		{
		case 'P':
		{
			print_numbers(numbers);
			break;
		}
		case 'A':
		{
			add_number(numbers);
			break;
		}
		case 'M':
		{
			calculate_mean(numbers);
			break;
		}
		case 'S':
		{
			calculate_smallest_number(numbers);
			break;
		}
		case 'L':
		{
			calculate_largest_number(numbers);
			break;
		}
		}
	} while (selected_option != 'Q');
	return 0;
}

char display_menu()
{
	char option{};
	cout << "------------------------------------\n";
	cout << "Enter your choice: \n";
	cout << "1. Print numbers (P)\n";
	cout << "2. Add a number (A)\n";
	cout << "3. Display mean of the numbers (M)\n";
	cout << "4. Display the smallest number (S)\n";
	cout << "5. Display the largest number (L)\n";
	cout << "6. Quit (Q)\n";
	cin >> option;
	return toupper(option);
}

void print_numbers(const vector<int> numbers)
{
	cout << "\nYour numbers are: [";
	for (auto n : numbers)
		cout << n << " ";
	cout << "]" << endl;
}

void add_number(vector<int> &numbers)
{
	int number{};
	cout << "\nEnter a number: ";
	cin >> number;
	numbers.push_back(number);
	cout << number << " added." << endl;
}

void calculate_mean(const vector<int> numbers)
{
	if (numbers.size() == 0)
	{
		cout << "Unable to calculate the mean - no data." << endl;
		return;
	}
	cout << "\nThe mean of the numbers is: ";
	double sum{};
	for (auto n : numbers)
		sum += n;
	cout << setprecision(2) << fixed;
	cout << sum / numbers.size() << endl;
}

void calculate_smallest_number(const vector<int> numbers)
{
	if (numbers.size() == 0)
	{
		cout << "Unable to calculate the smallest number - the list is empty." << endl;
		return;
	}
	cout << "\nThe smallest number is: ";
	int min{INT_MAX};
	for (auto n : numbers)
		min = n < min ? n : min;
	cout << min << endl;
}

void calculate_largest_number(const vector<int> numbers)
{
	if (numbers.size() == 0)
	{
		cout << "Unable to calculate the largest number - the list is empty." << endl;
		return;
	}
	cout << "\nThe largest number is: ";
	int max{INT_MIN};
	for (auto n : numbers)
		max = n > max ? n : max;
	cout << max << endl;
}
