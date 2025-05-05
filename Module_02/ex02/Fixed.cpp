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
	Fixed	temp;

	temp = this->_value + other._value;
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	temp;

	temp = this->_value - other._value;
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	temp;

	temp = this->_value * other._value;
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	temp;

	temp = this->_value / other._value;
	return (temp);
}

// *** EX02: Implementierung ***

// Vergleichsoperatoren (vergleich Raw-Bits):
// Schreibe jede Funktion als Einzeiler, z.B.:
// bool Fixed::operator>(const Fixed &other) const {
//     return this->_value > other._value;
// }

// Arithmetik: Beachte Skalierung mit _fract_bits:
// - Option A: Konvertiere beide Operanden mit toFloat(), rechne, und baue Fixed zurück
// - Option B: Rechne direkt mit _value (vorsichtig bei Überlauf)
// Beispiel Gerüst:
// Fixed Fixed::operator+(const Fixed &other) const {
//     Fixed result;
//     result._value = this->_value + other._value;
//     return result;
// }

// Inkrement/Dekrement: Der kleinste Schritt ist 1 << 0 (also 1 im Raw-Format)
// Pre-Inkrement:
// Fixed &Fixed::operator++() {
//     this->_value += 1;
//     return *this;
// }
// Post-Inkrement:
// Fixed Fixed::operator++(int) {
//     Fixed temp(*this);
//     ++(*this);
//     return temp;
// }

// Ähnliche Umsetzung für --

// min / max:
// Wähle anhand von Vergleichsoperatoren:
// Fixed &Fixed::min(Fixed &a, Fixed &b) {
//     return (a < b) ? a : b;
// }
// const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
//     return (a < b) ? a : b;
// }
// max analog.

// -----
// Deine Aufgabe:
// 1. Übernimm die Deklarationen oben in Fixed.hpp.
// 2. Schreibe die Methoden in Fixed.cpp anhand der Kommentare.
// 3. Kompiliere und teste jeden Operator einzeln, um zu verstehen, wie er wirkt.
// 4. Melde dich, wenn du bei einem spezifischen Operator unsicher bist!
