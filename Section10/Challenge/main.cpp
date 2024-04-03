#include <iostream>
#include <string>

using namespace std;

int main()
{
	string alphabet	{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string key			{"ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba"};
	string message;
	string encoded;
	string original;

	cout << "Enter a secret message: ";
	getline(cin, message);

	for(auto chr: message) {
		size_t pos{alphabet.find(chr)};
		if(pos == string::npos || pos >= key.length()) {
			encoded += chr;
			continue;
		}
		encoded += key[pos];
	}

	cout << "Encoded message: " << encoded << endl;

	for(auto chr: encoded) {
		size_t pos{key.find(chr)};
		if(pos == string::npos || pos >= alphabet.length()) {
			original += chr;
			continue;
		}
		original += alphabet[pos];
	}

	cout << "Original message: " << original << endl;

	return 0;
}