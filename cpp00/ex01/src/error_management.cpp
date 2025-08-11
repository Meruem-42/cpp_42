/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:08:40 by meruem            #+#    #+#             */
/*   Updated: 2025/08/11 13:18:29 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

void protection_cin()
{
    if (std::cin.eof())
    {
        std::cout << std::endl;
        std::cout << "error : end of file cin need to exit" << std::endl;
        exit(1);
    }
}