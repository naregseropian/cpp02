#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
	    Fixed();
        Fixed(const Fixed& other); // copy constructor
        Fixed(const int _ivalue);
        Fixed(const float _fvalue);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
        float toFloat( void ) const;
        int toInt( void ) const;
    
    private:
        int _value; // fixed-point number value
        static const int _fracBits = 8; // number of fractional bits
};

std::ostream& operator<<(std::ostream& COUT, const Fixed& rhs);

#endif