#include <iostream>

using namespace std;

int main() 
{
	int num1{10};
	int num2{20};
	int *number {&num1};

	cout << number[0] << endl;
	cout << number[-1] << endl;
	
	// cout << &num1 << endl;
	cout << &num2 << endl;
}