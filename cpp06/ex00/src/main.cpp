/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:13:29 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/08 12:13:30 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "wrong number of argument" << std::endl;
        return (1);
    }
    // ScalarConverter test;
    // std::string a;
    // a = av[1];
    // std::cout << "the scalar " << av[1] << std::endl;
    // std::cout << "the len of the scalar " << a.length() << std::endl;
    ScalarConverter::convert(av[1]);
}

