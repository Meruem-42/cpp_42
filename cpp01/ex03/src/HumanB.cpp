/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:53:03 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/11 23:49:55 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

void HumanB::setWeapon(Weapon& weapon)
{
    w = &weapon;
}

void HumanB::attack()
{
    if (!w)
        std::cout << name << " can't attack without weapon " << std::endl;
    else
        std::cout << name << " attacks with their " << (*w).getType() << std::endl;
}