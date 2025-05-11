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

bool Fixed::operator>(const Fixed &other) const  { return _value > other._value; }
bool Fixed::operator<(const Fixed &other) const  { return _value < other._value; }
bool Fixed::operator>=(const Fixed &other) const { return _value >= other._value; }
bool Fixed::operator<=(const Fixed &other) const { return _value <= other._value; }
bool Fixed::operator==(const Fixed &other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed &other) const { return _value != other._value; }

Fixed	Fixed::operator+(const Fixed &other) const
{
	int rawSum = _value + other._value;
    return Fixed(rawSum);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	temp;

	temp._value = this->_value - other._value;
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	temp;
	long	rawProduct;

	rawProduct = (long)this->_value * other._value;
	temp._value = rawProduct >> _fract_bits;
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	temp;
	int		rawProduct;

	long numerator = (long)this->_value << _fract_bits;
	rawProduct = numerator / other._value;
	temp.setRawBits(rawProduct);
	return (temp);
}

Fixed	&Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value++;
	return(temp);
}

Fixed	&Fixed::operator--()
{
	this->_value--;
	return (*this);
}
Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return(temp);
}

Fixed		&Fixed::min(Fixed &a, Fixed &b) { return (a < b ? a : b); }
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {return (a < b ? a : b); }
Fixed		&Fixed::max(Fixed &a, Fixed &b) { return (a > b ? a : b); }
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {return (a > b ? a : b); }