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

bool is_num(char c)
{
    if(c >= '0' && c <= '9')
        return (true);
    return (false); 
}

bool is_digit(const std::string str)
{
    int count_dot = 0;
    for (unsigned long i = 0; i < str.length(); ++i)
    {
        if((str[0] == '-' || str[0] == '+') && i == 0)
            ++i;
        if(str[i] == '.')
            ++count_dot;
        if(str[i] == 'f' && i != str.length() - 1)
            return (false);
        if(str[i] != '.' && str[i] != 'f' && !is_num(str[i]))
            return (false);
    }
    if(count_dot > 1)
        return (false);
    return (true);
}

bool is_char(const std::string str)
{
    if(str.length() != 3)
        return (false);
    if (str[0] == '\'' && str[2] == '\'')
        return (true);
    else
        return (false);
}

bool is_int(const std::string str)
{
    for (unsigned long i = 0; i < str.length(); ++i)
    {
        if((str[0] == '-' || str[0] == '+') && i == 0)
            ++i;
        if(is_num(str[i]))
            ++i;
        else
            return (false);
    }
    return (true);
}

bool is_special_float(const std::string str)
{
    if(str == "nanf" || str == "+inff" || str == "-inff")
        return (true);
    return (false);
}

bool is_float(const std::string str)
{
    if(is_digit(str))
    {
        for(unsigned long i = 0; i < str.length(); ++i)
        {
            if((str[0] == '-' || str[0] == '+') && i == 0)
                ++i;
            if(str[i] == '.' && str[str.length() - 1] == 'f')
                return (true);
        }
    }
    return (false);
}

bool is_special_double(const std::string str)
{
    if(str == "nan" || str == "+inf" || str == "-inf")
        return (true);
    return (false);
}

bool is_double(const std::string str)
{
    unsigned long i = 0;
    if(is_digit(str))
    {
        if((str[0] == '-' || str[0] == '+') && i == 0)
            ++i;
        while(i < str.length() && (is_num(str[i]) || str[i] == '.'))
        {
            if(str[i] == '.')
                return (true);
            ++i;
        }
    }
    return (false);
}

void ScalarConverter::convert(const std::string scalar)
{
    //identify scalar type
    if(is_char(scalar))
        convert_from_char(scalar[1]);
    else if (is_special_double(scalar))
        convert_special_double(scalar);
    else if (is_special_float(scalar))
        convert_special_float(scalar);
    else if (is_float(scalar))
        convert_from_float(scalar);
    else if (is_double(scalar))
        convert_from_double(scalar);
    else if (is_int(scalar))
        convert_from_int(scalar);
    else
        convert_from_error();
    //convert it to this scalar type
    //convert it to other data types
}