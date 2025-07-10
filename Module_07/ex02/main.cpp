#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
	Array<int> a(3);
	a[0] = 10; a[1] = 20; a[2] = 30;

	Array<int> b = a; // copy constructor
	Array<int> c;
	c = a; // assignment

	a[0] = 99; // check deep copy
	std::cout << "a[0]: " << a[0] << ", b[0]: " << b[0] << ", c[0]: " << c[0] << "\n";

	try {
		a[3] = 0;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	Array<std::string> s(2);
	s[0] = "Hello";
	s[1] = "World";
	std::cout << "s[0]: " << s[0] << ", s[1]: " << s[1] << "\n";

	return 0;
}
