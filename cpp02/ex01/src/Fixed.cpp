/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:32:47 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/15 15:33:24 by meruem           ###   ########.fr       */
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