#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <utility>
#include <algorithm>

class PmergeMe
{
	public:
		static void	bigAhhJohnsonSort( std::vector<int> &vec );
		static void	bigAhhJohnsonSort( std::deque<int> &deq );

	private:
		PmergeMe();
		PmergeMe( const PmergeMe &other );
		PmergeMe	&operator = (const PmergeMe &other );
		~PmergeMe();

		static std::vector< std::pair<int, int> >	createPairs( std::vector<int> &vec );
		static std::deque< std::pair<int, int> >	createPairs( std::deque<int> &deq );

		static std::vector<int>	createMainChain( const std::vector< std::pair<int, int> >& pairs );
		static std::deque<int>	createMainChain( const std::deque< std::pair<int, int> >& pairs );

		static void insertSorted( std::vector<int>& vec, int value );
		static void insertSorted( std::deque<int>& deq, int value );
};
