/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:04:29 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/24 15:33:53 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

void ClapTrap::attack(const std::string &target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage !" << std::endl;
        --energy_points;
    }
    else
        std::cout << "ClapTrap " << name << " cant attack check HP(" << hit_points << ") or HE(" << energy_points << ") too low" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " took " << amount << " points of damage !" << std::endl;
    hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "ClapTrap " << name << " repaired " << amount << " hit points !" << std::endl;
        --energy_points;
        hit_points += amount;
    }
    else
        std::cout << "ClapTrap " << name << " cant repair check HP(" << hit_points << ") or HE(" << energy_points << ") too low" << std::endl;
}