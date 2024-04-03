#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// vector<char> vowels {'a', 'e', 'i', 'o', 'u', 'y'};
	// vector<char> vowels(5, 'a');

	// cout << vowels[0] << endl;
	// cout << vowels[4] << endl;

	vector<int> test_scores{100, 98, 89};

	cout << "Test scores using array syntax:\n";
	cout << test_scores[0] << '\n';
	cout << test_scores[1] << '\n';
	cout << test_scores[2] << '\n';

	cout << "There are "
			 << test_scores.size()
			 << " scores (of "
			 << test_scores.capacity()
			 << ") in the vector.\n";

	cout << "Test scores using vector syntax:\n"
			 << test_scores.at(0) << '\n'
			 << test_scores.at(1) << '\n'
			 << test_scores.at(2) << '\n';

	cout << "Enter 3 test scores:\n";
	cin >> test_scores.at(0);
	cin >> test_scores.at(1);
	cin >> test_scores.at(2);

	cout << "Updated test scores:\n"
			 << test_scores.at(0) << '\n'
			 << test_scores.at(1) << '\n'
			 << test_scores.at(2) << '\n';

	int new_element{0};
	cout << "Enter a number to add to the vector:\n";
	cin >> new_element;

	test_scores.push_back(new_element);

	cout << "Enter another number to add to the vector:\n";
	cin >> new_element;

	test_scores.push_back(new_element);

	cout << "Final test scores:\n"
			 << test_scores.at(0) << '\n'
			 << test_scores.at(1) << '\n'
			 << test_scores.at(2) << '\n'
			 << test_scores.at(3) << '\n'
			 << test_scores.at(4) << '\n';

	cout << "There are now " << test_scores.size() << " scores in the vector.\n";

	cout << "Accessing 10: " << test_scores.at(10);
}