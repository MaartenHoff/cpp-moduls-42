#include "easyfind.hpp"
#include <vector>

int	main(void) {
	std::vector<int> has_value;
	has_value.push_back(1);
	has_value.push_back(2);
	has_value.push_back(3);
	has_value.push_back(4);
	has_value.push_back(5);

	std::vector<int> no_value;
	no_value.push_back(1);
	no_value.push_back(2);
	no_value.push_back(3);
	no_value.push_back(5);
	no_value.push_back(6);

	try
	{
		std::cout << *easyfind(has_value, 4) << std::endl;
		std::cout << *easyfind(no_value, 4) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}