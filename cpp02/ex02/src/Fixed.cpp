/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:32:47 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/24 12:12:34 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int Fixed::getRawBits(void) const
{
    return (fixed_number);
}

void Fixed::setRawBits(int const raw)
{
    fixed_number = raw;
}

float Fixed::toFloat(void) const
{
    float temp;

    temp = fixed_number;
    return (temp / 256.0f);
}

int Fixed::toInt(void) const
{
    return (fixed_number / 256);
}

std::ostream &operator<<(std::ostream &cout, const Fixed &x)
{
    return (cout << x.toFloat());
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed res;
    res.setRawBits(this->getRawBits() + other.getRawBits());
    return (res);
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed res;
    res.setRawBits(this->getRawBits() - other.getRawBits());
    return (res);
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed res;
    res.setRawBits(roundf(this->getRawBits() * other.getRawBits() / 256));
    return (res);
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed res;
    res.setRawBits(roundf(this->getRawBits() / other.getRawBits() * 256));
    return (res);
}

bool Fixed::operator>(const Fixed& other) const
{
    if (this->getRawBits() > other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed& other) const
{
    if (this->getRawBits() > other.getRawBits())
        return (false);
    return (true);
}

bool Fixed::operator>=(const Fixed& other) const
{
    if (this->getRawBits() >= other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& other) const
{
    if (this->getRawBits() > other.getRawBits())
        return (false);
    return (true);
}

bool Fixed::operator==(const Fixed& other) const
{
    if (this->getRawBits() == other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& other) const
{
    if (this->getRawBits() == other.getRawBits())
        return (false);
    return (true);
}

Fixed Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp;

    temp.setRawBits(this->getRawBits());
    this->setRawBits(this->getRawBits() + 1);
    return (temp);
}

Fixed Fixed::operator--()
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp;

    temp.setRawBits(this->getRawBits());
    this->setRawBits(this->getRawBits() - 1);
    return (temp);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
    if (first > second)
        return (second);
    return (first);
}

Fixed const &Fixed::min(Fixed const &first, Fixed const &second)
{
    if (first > second)
        return (second);
    return (first);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
    if (first > second)
        return (first);
    return (second);
}

Fixed const &Fixed::max(Fixed const &first, Fixed const &second)
{
    if (first > second)
        return (first);
    return (second);
}