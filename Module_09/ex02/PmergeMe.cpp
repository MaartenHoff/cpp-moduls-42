#include "PmergeMe.hpp"

std::vector< std::pair<int, int> >	PmergeMe::createPairs( std::vector<int> &vec ) {
	std::vector< std::pair<int, int> > pairs;

	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	return pairs;
}

std::deque< std::pair<int, int> >	PmergeMe::createPairs( std::deque<int> &deq ) {
	std::deque< std::pair<int, int> > pairs;

	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		int a = deq[i];
		int b = deq[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	return pairs;
}

std::vector<int>	PmergeMe::createMainChain( const std::vector< std::pair<int, int> >& pairs ) {
	std::vector<int>	mainChain;
	if (pairs.empty())
			return mainChain;
	
	mainChain.push_back(pairs[0].first);

	for (size_t i = 0; i < pairs.size(); ++i) {
		mainChain.push_back(pairs[i].second);
	}

	std::sort(mainChain.begin(), mainChain.end());
	return (mainChain);
}

std::deque<int>	PmergeMe::createMainChain( const std::deque< std::pair<int, int> >& pairs ) {
	std::deque<int>	mainChain;
	if (pairs.empty())
			return mainChain;

	mainChain.push_back(pairs[0].first);

	for (size_t i = 0; i < pairs.size(); ++i) {
		mainChain.push_back(pairs[i].second);
	}

	std::sort(mainChain.begin(), mainChain.end());
	return (mainChain);
}

void PmergeMe::insertSorted( std::vector<int>& vec, int value ) {
	std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
	vec.insert(it, value);
}

void PmergeMe::insertSorted( std::deque<int>& deq, int value ) {
	std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), value);
	deq.insert(it, value);
}

void	PmergeMe::bigAhhJohnsonSort( std::vector<int> &vec ) {
	int rest = -1;
	if (vec.size() % 2 != 0)
	{
		rest = vec.back();
		vec.pop_back();
	}

	std::vector< std::pair<int, int> > pairs;
	pairs = PmergeMe::createPairs(vec);

	std::vector<int>	mainChain;
	mainChain = PmergeMe::createMainChain(pairs);

	for (size_t i = 1; i < pairs.size(); i++) {
		PmergeMe::insertSorted( mainChain, pairs[i].first);
	}

	if (rest != -1)
		PmergeMe::insertSorted( mainChain, rest);

	vec = mainChain;
}

void	PmergeMe::bigAhhJohnsonSort( std::deque<int> &deq ) {
	int rest = -1;
	if (deq.size() % 2 != 0)
	{
		rest = deq.back();
		deq.pop_back();
	}

	std::deque< std::pair<int, int> > pairs;
	pairs = PmergeMe::createPairs(deq);

	std::deque<int>	mainChain;
	mainChain = PmergeMe::createMainChain(pairs);

	for (size_t i = 1; i < pairs.size(); i++) {
		PmergeMe::insertSorted( mainChain, pairs[i].first);
	}

	if (rest != -1)
		PmergeMe::insertSorted( mainChain, rest);

	deq = mainChain;
}

