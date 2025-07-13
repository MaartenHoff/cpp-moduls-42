#include "Span.hpp"

Span::Span( unsigned int N ) : _maxSize(N) {}

Span::Span( const Span &other ) : _nums(other._nums), _maxSize(other._maxSize) {}

Span	&Span::operator = ( const Span &other ) {
	if (this != &other) {
		if (other._maxSize != _maxSize)
			throw AnException("Can't assign two Spans with different sizes!");
		_nums = other._nums;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber( int num ) {
	if (_nums.size() >= _maxSize)
		throw AnException("Can't add another number! Max amount already reached.");
	_nums.push_back(num);
}

int		Span::shortestSpan() {
	if (_nums.size() < 2)
		throw AnException("At least 2 Numbers needed to check for the shortest Span!");
	std::vector<int> sorted = _nums;
	std::sort(sorted.begin(), sorted.end());
	int	shortestSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; i++) {
		int temp = sorted[i + 1] - sorted[i];
		if (temp < shortestSpan)
			shortestSpan = temp;
	} 
	return (shortestSpan);
}

int		Span::longestSpan() {
	if (_nums.size() < 2)
		throw AnException("At least 2 Numbers needed to check for the shortest Span!");
	int min = *std::min_element(_nums.begin(), _nums.end());
	int max = *std::max_element(_nums.begin(), _nums.end());
	return max - min;
}