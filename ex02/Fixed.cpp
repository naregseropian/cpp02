#include "Fixed.hpp"

// -------------- constructors --------------

Fixed::Fixed()
{
    std::cout << "Default Constructor called" << std::endl;
    _value = 0;
    return;
}

Fixed::Fixed(const int ivalue)
{
    std::cout << "Int Constructor called" << std::endl;
    _value = ivalue << _fracBits;
    return;
}

Fixed::Fixed(const float fvalue)
{
    std::cout << "Float Constructor called" << std::endl;
    _value =  roundf(fvalue * (1 << _fracBits));
    return;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = other;
    return;
}

// -------------- destructor --------------

Fixed::~Fixed()
{
    std::cout << "Default Destructor called" << std::endl;
    return;
}

// -------------- overload assignment operator --------------

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) // handles self assignment
        this->_value = rhs.getRawBits();
    return *this;
}

// -------------- overload arithmetic operators --------------

Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed temp;
    temp._value = _value + rhs._value;
    return temp;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed temp;
    temp._value = _value - rhs._value;
    return temp;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed temp;
    temp._value = (_value * rhs._value) >> _fracBits;
    return temp;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    Fixed temp;
    temp._value = (_value << _fracBits) / rhs._value;
    return temp;
}

// -------------- overload comparison operators --------------

bool Fixed::operator>(const Fixed& rhs) const
{
    return (_value > rhs._value);
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return (_value < rhs._value);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return (_value >= rhs._value);
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return (_value <= rhs._value);
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return (_value == rhs._value);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return (_value != rhs._value);
}

// -------------- overload incrementation --------------

Fixed& Fixed::operator++(void)
{
    (this->_value)++;
    return *this;
}

Fixed& Fixed::operator--(void)
{
    (this->_value)--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _value++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _value--;
    return temp;
}

// -------------- member functions --------------

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void Fixed::setRawBits( int const raw )
{
    _value = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)_value / (float)(1 << _fracBits));
}

int Fixed::toInt( void ) const
{
    return ((_value ^ _fracBits) >> _fracBits);
}

// -------------- static member functions --------------

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

// -------------- global functions --------------

std::ostream& operator<<(std::ostream& COUT, const Fixed& rhs)
{
    COUT << rhs.toFloat();
    return COUT;
}