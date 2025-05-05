#include "Fixed.hpp"

Fixed::Fixed() : _value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed( const Fixed &copy )
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    _value = num << _fract_bits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(roundf(num * (1 << _fract_bits)));
}

Fixed &Fixed::operator = ( const Fixed &src )
{
	std::cout << "Copy assignment operator called\n";
	
	if (this != &src)
        _value = src._value;
	return (*this);
}	

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_value) / (1 << _fract_bits);
}

int Fixed::toInt(void) const
{
    return _value >> _fract_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &number)
{
    out << number.toFloat();
    return out;
}
