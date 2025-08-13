#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int fixed_number;
    static const int bits_number = 8;

public:
    Fixed();
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

Fixed::Fixed()
    : fixed_number(0) {}

Fixed::~Fixed()
{
}

#endif