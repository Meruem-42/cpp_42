/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:08:40 by meruem            #+#    #+#             */
/*   Updated: 2025/08/17 18:15:23 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

int protection_cin()
{
    if (std::cin.eof())
    {
        std::cout << std::endl;
        std::cout << "error : end of file cin need to exit" << std::endl;
        return (1);
    }
    return (0);
}