#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str{};
	cout << "Enter a string to create the pyramid with: ";
	getline(cin, str);
	size_t len = str.length();

	for (size_t i{1}; i <= len; i++)
	{
		string s1{str.substr(0, i)};
		string filler(len - i, ' ');
		string reverse{};
		for (size_t j{0}; j < (s1.length() - 1); j++)
		{
			reverse = str[j] + reverse;
		}

		cout << filler << s1 << reverse << filler << endl;
	}

	return 0;
}