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
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
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
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i] == '.' && is_num(str[i]))
            ++i;
        else
            return (false);
    }
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
    for (int i = 0; i < str.length(); ++i)
    {
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
        for(int i = 0; i < str.length(); ++i)
        {
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
    if(is_digit(str))
    {
        for(int i = 0; i < str.length() && is_num(str[i]); ++i)
        {
            if(str[i] == '.')
                return (true);
        }        
    }
    return (false);
}

void ScalarConverter::convert(const std::string scalar)
{
    //identify scalar type
    //convert it to this scalar type
    //convert it to other data types
}