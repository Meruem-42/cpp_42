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
        // std::cout << "Default constructor called" << std::endl;
    }

    Fixed(const int real_value)
    {
        // std::cout << "Int constructor called" << std::endl;
        if (real_value > 2147483647 / 256)
            std::cout << "Note that the results won't be accurate with the input: " << real_value << std::endl;
        fixed_number = real_value * 256;
    }

    Fixed(const float real_value)
    {
        // std::cout << "Float constructor called" << std::endl;
        if (real_value > 2147483647 / 256)
           std::cout << "Note that the results won't be accurate with the input: " << real_value << std::endl; 
        fixed_number = roundf(real_value * 256);
    }

    Fixed(const Fixed &other)
    {
        // std::cout << "Copy constructor called" << std::endl;
        *this = other;
    }

    Fixed &operator=(const Fixed &other)
    {
        // std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other)
            fixed_number = other.getRawBits();
        return (*this);
    }

    ~Fixed()
    {
        // std::cout << "Destructor called" << std::endl;
    }

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator++();
    Fixed operator++(int);
    Fixed operator--();
    Fixed operator--(int);

    static Fixed &min(Fixed &first, Fixed &second);
    static Fixed const &min(Fixed const &first, Fixed const &second);
    static Fixed &max(Fixed &first, Fixed &second);
    static Fixed const &max(Fixed const &first, Fixed const &second);



    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &cout, const Fixed &x);

#endif