#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
    private:
        int _value; // fixed-point number value
        static const int _fracBits = 8; // number of fractional bits
    public:
	    Fixed();
        Fixed(const Fixed& other); // copy constructor
	    
        Fixed& operator=(const Fixed& rhs); // copy assignment operator overload

        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif
