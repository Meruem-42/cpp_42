#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

    ~Fixed()
    {
        std::cout << "Destructor called" << std::endl;
    }

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif