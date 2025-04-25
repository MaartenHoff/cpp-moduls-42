#pragma once
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed( const Fixed &copy );
		Fixed &operator = (const Fixed &src);
		~Fixed();
	
	private:
		int			_value;
		const int	_bits;
};
