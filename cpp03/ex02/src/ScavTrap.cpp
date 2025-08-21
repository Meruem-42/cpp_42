/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:26:17 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/21 17:43:45 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

void ScavTrap::attack(const std::string &target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage !";
        --energy_points;
        std::cout << " Energy left: " << energy_points << std::endl;
    }
    else
        std::cout << "ScavTrap " << name << " cant attack check HP(" << hit_points << ") or HE(" << energy_points << ") too low" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is in Gate Keeper mode" << std::endl;
}
