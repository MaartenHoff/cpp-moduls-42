#include "MutantStack.hpp"
#include <cassert>
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::list<int> lst;

	mstack.push(5);		lst.push_back(5);
	mstack.push(17);	lst.push_back(17);
	mstack.pop();		lst.pop_back();
	mstack.push(3);		lst.push_back(3);
	mstack.push(5);		lst.push_back(5);
	mstack.push(737);	lst.push_back(737);
	mstack.push(0); 	lst.push_back(0);

	assert(mstack.size() == lst.size());

	MutantStack<int>::iterator it1 = mstack.begin();
	MutantStack<int>::iterator ite1 = mstack.end();

	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();

	while (it1 != ite1 && it2 != ite2) {
		assert(*it1 == *it2);
		std::cout << "mstack: " << *it1 << "\tlst: " << *it2 << std::endl;
		++it1; ++it2;
	}
	assert(it1 == ite1 && it2 == ite2);

	return 0;
}
