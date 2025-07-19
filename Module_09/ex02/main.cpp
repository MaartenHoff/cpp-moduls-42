#include "PmergeMe.hpp"
#include <sys/time.h>

bool isValid(const std::string& input) {
	for (size_t i = 0; i < input.length(); ++i)
		if (!isdigit(input[i]))
			return false;
	return !input.empty();
}

long long getTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return static_cast<long long>(tv.tv_sec) * 1000000 + tv.tv_usec;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; ++i) {
		std::string arg(argv[i]);
		if (!isValid(arg)) {
			std::cerr << "Error: invalid argument '" << arg << "'" << std::endl;
			return 1;
		}
		int value = std::atoi(argv[i]);
		vec.push_back(value);
		deq.push_back(value);
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	long long startVec = getTime();
	PmergeMe::bigAhhJohnsonSort(vec);
	long long endVec = getTime();

	long long startDeq = getTime();
	PmergeMe::bigAhhJohnsonSort(deq);
	long long endDeq = getTime();

	std::cout << "After:  ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << (endVec - startVec) << " us" << std::endl;

	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque:  " << (endDeq - startDeq) << " us" << std::endl;

	return 0;
}
