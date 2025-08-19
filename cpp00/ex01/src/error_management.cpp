/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:08:40 by meruem            #+#    #+#             */
/*   Updated: 2025/08/19 19:24:49 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/global.hpp"

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

int is_empty(std::string field)
{
    for (int i = 0; field[i]; ++i)
    {
        if (field[i] > 32)
            return (0);
    }
    return (1);
}