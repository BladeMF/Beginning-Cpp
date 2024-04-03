// Section 14
// Challenge
#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
	Mystring s1{"George"};
	Mystring s2 = -s1;
	cout << s2 << endl;

	cout << "(s1 == s2) = " << (s1 == s2) << ", (s1 != s2) = " << (s1 != s2) << endl;
	Mystring s3{"George"};
	cout << "(s1 == s3) = " << (s1 == s3) << ", (s1 != s3) = " << (s1 != s3) << endl;

	Mystring a{"a"};
	Mystring b{"b"};
	cout << "(a < b) = " << (a < b) << ", (a > b) = " << (a > b) << endl;

  Mystring joe_is{"Joe is "};
  Mystring tha_man{"tha man"};
	cout << (joe_is + tha_man) << endl;

	Mystring joe_is2{"Joe is "};
  Mystring tha_man2{"tha man"};
	joe_is2 += tha_man2;
	cout << (joe_is2) << endl;

	Mystring joe{"Joe "};
	cout << (joe * 5) << endl;

	Mystring tha_man3{"Tha man "};
	tha_man3 *= 5;
	cout << (tha_man3) << endl;
	/*

	cout << boolalpha << endl;
	Mystring a {"frank"};
	Mystring b {"frank"};

	cout << (a==b) << endl;         // true
	cout << (a!=b) << endl;          // false

	b = "george";
	cout << (a==b) << endl;         // false
	cout << (a!=b) << endl;          // true
	 cout << (a<b) << endl;          // true
	cout << (a>b) << endl;           // false

	Mystring s1 {"FRANK"};
	s1 = -s1;
	cout << s1 << endl;               // frank

	s1 = s1 + "*****";
	cout << s1 << endl;               // frank*****

	s1 += "-----";                        // frank*****-----
	cout << s1 << endl;

	Mystring s2{"12345"};
	s1 = s2 * 3;
	cout << s1 << endl;              // 123451234512345

	Mystring s3{"abcdef"};
	s3 *= 5;
	cout << s3 << endl;             // abcdefabcdefabcdefabcdefabcdef

	Mystring s = "Frank";
	++s;
	cout << s << endl;                  // FRANK

	s = -s;
	cout << s << endl;                  // frank

	Mystring result;
	result = ++s;
	cout << s << endl;                  // FRANK
	cout << result << endl;           // FRANK

	s = "Frank";
	s++;
	cout << s << endl;                  // FRANK

	s = -s;
	cout << s << endl;                  // frank
	result = s++;
	cout << s << endl;                  // FRANK
	cout << result << endl;           // frank

	*/
	return 0;
}
