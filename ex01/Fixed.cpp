#include "Fixed.hpp"

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

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) // handles self assignment
        this->_value = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Default Destructor called" << std::endl;
    return;
}

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
    return (_value >> _fracBits);
}

std::ostream& operator<<(std::ostream& COUT, const Fixed& rhs)
{
    COUT << rhs.toFloat();
    return COUT;
}