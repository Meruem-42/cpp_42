#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
private:
    int fixed_number;
    static const int bits_number = 8;

public:
    Fixed()
        : fixed_number(0)
    {
        std::cout << "Default constructor called" << std::endl;
    }

    Fixed(const int real_value)
    {
        std::cout << "Int constructor called" << std::endl;
        fixed_number = real_value * 256;
    }

    Fixed(const float real_value)
    {
        std::cout << "Float constructor called" << std::endl;
        fixed_number = roundf(real_value * 256);
    }

    Fixed(const Fixed &other)
    {
        std::cout << "Copy constructor called" << std::endl;
        *this = other;
    }

    Fixed &operator=(const Fixed &other)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other)
            fixed_number = other.getRawBits();
        return (*this);
    }

    friend std::ostream &operator<<(std::ostream &cout, const Fixed &x)
    {
        return (cout << x.toFloat());
    }

    ~Fixed()
    {
        std::cout << "Destructor called" << std::endl;
    }

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

#endif