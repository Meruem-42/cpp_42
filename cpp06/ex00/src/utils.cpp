/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:52:09 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/13 17:52:10 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>

void convert_from_int(std::string scalar)
{
    std::stringstream ss(scalar);
    int test;

    ss >> test;

    std::cout << "char : ";
    if (test > 32 && test < 126)
         std::cout << "'" << static_cast<char>(test) << "'" << std::endl;  
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int : " << test << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float : " << static_cast<float>(test) << "f" << std::endl;  
    std::cout << "double : "  << static_cast<double>(test) << std::endl;  
}

void convert_from_float(std::string scalar)
{
    std::stringstream ss(scalar);
    float test;

    ss >> test;

    std::cout << "char : ";
    if (test > 32 && test < 126)
         std::cout << "'" << static_cast<char>(test) << "'" << std::endl;  
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int : " << static_cast<int>(test) << std::endl;
    std::cout << "float : " << test << "f" << std::endl;  
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double : "  << static_cast<double>(test) << std::endl;  
}
