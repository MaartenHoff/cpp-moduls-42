#pragma once
#include <iostream>
#include <math.h>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed( const Fixed &copy );
		Fixed( const int num );
		Fixed( const float num );

		Fixed &operator = ( const Fixed &src );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
	
	private:
		int					_value;
		static const int	_fract_bits = 8;
};

std::ostream	&operator << (std::ostream& out, const Fixed& number);
