#include <iostream>

class Obj1
{
public:
	int prop1 {0};
};

void func1(Obj1 &obj) {
	std::cout << &obj << std::endl;
	obj.prop1 = 10;
}

int main(){
	Obj1 obj1;
	std::cout << &obj1 << std::endl;
	func1(obj1);
	std::cout << obj1.prop1 << std::endl;
}