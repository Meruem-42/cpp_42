/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:13:33 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/08 12:13:38 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string scalar)
{
    if(is_char(scalar))
        convert_from_char(scalar[1]);
    else if (is_special_double(scalar))
        convert_special_double(scalar);
    else if (is_special_float(scalar))
        convert_special_float(scalar);
    else if (!is_digit(scalar))
        return convert_from_error();
    else if (is_float(scalar))
        convert_from_float(scalar);
    else if (is_double(scalar))
        convert_from_double(scalar);
    else if (is_int(scalar))
        convert_from_int(scalar);
    else
        convert_from_error();
}