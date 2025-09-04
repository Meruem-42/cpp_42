/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:03:21 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/23 16:49:37 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

std::string WrongAnimal::getType() const
{
    return ((const std::string)type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal don't bark either" << std::endl;
}
