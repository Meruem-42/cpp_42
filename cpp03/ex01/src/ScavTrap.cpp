/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:26:17 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/20 21:55:12 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

void ScavTrap::attack(const std::string &target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage ! Energy left: " << energy_points << std::endl;
        --energy_points;
    }
    else
        std::cout << "ScavTrap " << name << " cant attack check HP(" << hit_points << ") or HE(" << energy_points << ") too low" << std::endl;
}
