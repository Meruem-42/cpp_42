/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:52:09 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/15 12:02:39 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cfloat>

void convert_from_char(char c)
{
    std::cout << "char : ";
         std::cout << "'" << c << "'" << std::endl;  
    std::cout << "int : " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;  
    std::cout << "double : "  << static_cast<double>(c) << std::endl;  
}

void convert_from_int(std::string scalar)
{
    std::stringstream ss(scalar);
    int test;

    ss >> test;
    if (ss.fail() || std::isinf(test))
        return (convert_from_error());
    std::cout << "char : ";
    if (test > 32 && test < 126)
         std::cout << "'" << static_cast<char>(test) << "'" << std::endl;  
    else if (test >= 0 && test < 32)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;
    std::cout << "int : " << test << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float : " << static_cast<float>(test) << "f" << std::endl;  
    std::cout << "double : "  << static_cast<double>(test) << std::endl;  
}

void convert_special_float(std::string scalar)
{
    if(scalar == "nanf")
        scalar = "nan";
    if(scalar == "+inff")
        scalar = "+inf";
    if(scalar == "-inff")
        scalar = "-inf";
    float test;

    // ss >> test;
    test = std::atof(scalar.c_str());

    std::cout << "char : ";
    std::cout << "impossible" << std::endl;
    std::cout << "int : " << "impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float : " << test << "f" << std::endl;  
    std::cout << "double : "  << static_cast<double>(test) << std::endl;  
}

void convert_special_double(std::string scalar)
{
    double test;
    char *end;

    test = std::strtod(scalar.c_str(), &end);

    std::cout << "char : ";
    std::cout << "impossible" << std::endl;
    std::cout << "int : " << "impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float : " << static_cast<float>(test) << "f" << std::endl;  
    std::cout << "double : "  << test << std::endl;  
}

void convert_from_float(std::string scalar)
{
    float test;

    test = std::atof(scalar.c_str());
    if (test < -FLT_MAX || test > FLT_MAX)
        return (convert_from_error());
    std::cout << "char : ";
    if (test > 32 && test < 126)
         std::cout << "'" << static_cast<char>(test) << "'" << std::endl;  
    else if (test >= 0 && test < 32)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;
    if (test < static_cast<float>(INT_MIN) || test > static_cast<float>(INT_MAX))
        std::cout << "int : " << "impossible" << std::endl;
    else
        std::cout << "int : " << static_cast<int>(test) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float : " << test << "f" << std::endl;
    std::cout << "double : "  << static_cast<double>(test) << std::endl;  
}

void convert_from_double(std::string scalar)
{
    std::stringstream ss(scalar);
    double test;

    ss >> test;
    if (ss.fail() || std::isinf(test))
        return (convert_from_error());
    std::cout << "char : ";
    if (test > 32 && test < 126)
         std::cout << "'" << static_cast<char>(test) << "'" << std::endl;  
    else if (test >= 0 && test < 32)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;
    if (test < INT_MIN || test > INT_MAX)
        std::cout << "int : " << "impossible" << std::endl;
    else
        std::cout << "int : " << static_cast<int>(test) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    if (static_cast<float>(test) < -FLT_MAX || static_cast<float>(test) > FLT_MAX)
        std::cout << "float : " << "impossible" << std::endl;
    else
        std::cout << "float : " << static_cast<float>(test) << "f" << std::endl;
    std::cout << "double : "  << test << std::endl;  
}

void convert_from_error(void)
{
    std::cout << "char : " << "impossible" << std::endl;
    std::cout << "int : " << "impossible" << std::endl;
    std::cout << "float : " << "impossible" << std::endl;  
    std::cout << "double : "  << "impossible" << std::endl;  
}
