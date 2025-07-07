#include "ScalarConverter.hpp"
#include <iostream>
#include <vector>

int main() {
	std::vector<std::string> tests;
	tests.push_back("a");         // char
	tests.push_back("z");         // char
	tests.push_back("42");        // int
	tests.push_back("-1337");     // int
	tests.push_back("3.14f");     // float
	tests.push_back("-0.42f");    // float
	tests.push_back("2.718");     // double
	tests.push_back("-1.1");      // double
	tests.push_back("nan");       // pseudo double
	tests.push_back("nanf");      // pseudo float
	tests.push_back("+inf");      // pseudo double
	tests.push_back("-inff");     // pseudo float
	tests.push_back("hello");     // invalid
	tests.push_back("123abc");    // invalid
	tests.push_back("");          // empty
	tests.push_back("127");       // int -> char edge case
	tests.push_back("128");       // out of char range
	tests.push_back("31");        // non-displayable char
	tests.push_back("non-display"); // invalid

	for (size_t i = 0; i < tests.size(); ++i) {
		std::cout << "Input: \"" << tests[i] << "\"" << std::endl;
		ScalarConverter::convert(tests[i]);
		std::cout << "--------------------------" << std::endl;
	}
	ScalarConverter::~ScalarConverter()
	return 0;
}
