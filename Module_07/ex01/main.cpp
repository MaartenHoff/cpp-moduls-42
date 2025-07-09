#include "iter.hpp"

int main() {
	std::cout << "\nnormal test:" << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, printElement);

	std::cout << "\ndiffrent type test:" << std::endl;
	std::string strArr[] = {"foo", "bar", "baz"};
	iter(strArr, 3, printElement);

	std::cout << "\nconst test:" << std::endl;
	int const arrConst[] = {1, 2, 3, 4, 5};
	iter(arrConst, 5, printConstElement);
	
	return (0);
}