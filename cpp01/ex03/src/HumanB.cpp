/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:53:03 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/11 19:23:21 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

void HumanB::setWeapon(Weapon weapon)
{
    w = &weapon;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << (*w).getType() << std::endl;
}