/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:04:29 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/23 15:50:18 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

std::string Animal::getType() const
{
    return ((const std::string)type);
}

void Animal::makeSound()
{
    if (type == "Cat")
        std::cout << "cats don't bark" << std::endl;
    if (type == "Dog")
        std::cout << "dogs bark" << std::endl;
}
