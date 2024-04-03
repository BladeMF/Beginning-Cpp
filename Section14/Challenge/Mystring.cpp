#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
		: str{nullptr}
{
	str = new char[1];
	*str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
		: str{nullptr}
{
	if (s == nullptr)
	{
		str = new char[1];
		*str = '\0';
	}
	else
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	std::cout << "char* constructor used" << std::endl;
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
		: str{nullptr}
{
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
	std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source)
		: str(source.str)
{
	source.str = nullptr;
	std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring()
{
	delete[] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
	std::cout << "Using copy assignment" << std::endl;

	if (this == &rhs)
		return *this;
	delete[] str;
	str = new char[strlen(rhs.str) + 1];
	strcpy(str, rhs.str);
	return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
	std::cout << "Using move assignment" << std::endl;

	if (this == &rhs)
		return *this;
	delete[] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

// Mystring Mystring::operator-()
// {
// 	char *buff = new char[strlen(str) + 1];
// 	for (size_t i = 0; i < strlen(str); i++)
// 	{
// 		buff[i] = tolower(str[i]);
// 	}
// 	Mystring result{buff};
// 	delete[] buff;
// 	return result;
// }

// bool Mystring::operator==(const Mystring &rhs)
// {
// 	return std::strcmp(str, rhs.str) == 0;
// }

// bool Mystring::operator!=(const Mystring &rhs)
// {
// 	return std::strcmp(str, rhs.str) != 0;
// }

// bool Mystring::operator<(const Mystring &rhs)
// {
// 	return std::strcmp(str, rhs.str) < 0;
// }

// bool Mystring::operator>(const Mystring &rhs)
// {
// 	return std::strcmp(str, rhs.str) > 0;
// }

// Mystring Mystring::operator+(const Mystring &rhs)
// {
// 	char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
// 	strcpy(buff, str);
// 	strcat(buff, rhs.str);
// 	Mystring str = {buff};
// 	delete[] buff;
// 	return str;
// }

// Mystring &Mystring::operator+=(const Mystring &rhs)
// {
// 	char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
// 	strcpy(buff, str);
// 	strcat(buff, rhs.str);
// 	delete str;
// 	str = buff;
// 	return *this;
// }

// Mystring Mystring::operator*(const int times)
// {
// 	char *buff = new char[strlen(str) * times + 1];
// 	strcpy(buff, str);
// 	for (int i = 1; i < times; i++)
// 		strcat(buff, str);
// 	Mystring new_str{buff};
// 	delete[] buff;
// 	return new_str;
// }

// Mystring &Mystring::operator*=(const int times)
// {
// 	char *buff = new char[strlen(str) * times + 1];
// 	strcpy(buff, str);
// 	for (int i = 1; i < times; i++)
// 		strcat(buff, str);
// 	delete str;
// 	str = buff;
// 	return *this;
// }

// Display method
void Mystring::display() const
{
	std::cout << str << " : " << get_length() << std::endl;
}

// getters
int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
	os << rhs.str;
	return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs)
{
	char *buff = new char[1000];
	in >> buff;
	rhs = Mystring{buff};
	delete[] buff;
	return in;
}

Mystring operator-(const Mystring &lhs)
{
	char *buff = new char[strlen(lhs.str) + 1];
	for (size_t i = 0; i < strlen(lhs.str); i++)
	{
		buff[i] = tolower(lhs.str[i]);
	}
	Mystring result{buff};
	delete[] buff;
	return result;
}

bool operator==(const Mystring &lhs, const Mystring &rhs)
{
	return std::strcmp(lhs.str, rhs.str) == 0;
}

bool operator!=(const Mystring &lhs, const Mystring &rhs)
{
	return std::strcmp(lhs.str, rhs.str) != 0;
}

bool operator<(const Mystring &lhs, const Mystring &rhs)
{
	return std::strcmp(lhs.str, rhs.str) < 0;
}

bool operator>(const Mystring &lhs, const Mystring &rhs)
{
	return std::strcmp(lhs.str, rhs.str) > 0;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
	char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
	strcpy(buff, lhs.str);
	strcat(buff, rhs.str);
	Mystring str = {buff};
	delete[] buff;
	return str;
}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs)
{
	char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
	strcpy(buff, lhs.str);
	strcat(buff, rhs.str);
	delete lhs.str;
	lhs.str = buff;
	return lhs;
}

Mystring operator*(const Mystring &lhs, const int times)
{
	int length = strlen(lhs.str) * times + 1;
	char *buff = new char[length];
	strcpy(buff, lhs.str);
	for (int i = 1; i < times; i++)
		strcat(buff, lhs.str);
	buff[length - 1] = '\0';
	Mystring new_str{buff};
	delete[] buff;
	return new_str;
}

Mystring &operator*=(Mystring &lhs, const int times)
{
	int length = strlen(lhs.str) * times + 1;
	char *buff = new char[length];
	strcpy(buff, lhs.str);
	for (int i = 1; i < times; i++)
		strcat(buff, lhs.str);
	buff[length - 1] = '\0';
	delete lhs.str;
	lhs.str = buff;
	return lhs;
}