/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:51:33 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/21 18:31:27 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main()
{
    ScavTrap a("Tom");
    ScavTrap b("Michel");
    ScavTrap c("Lou");
    ScavTrap d(a);

    a.attack("Michel");
    b.takeDamage(50);
    b.beRepaired(50);
    b.takeDamage(100);
    b.attack("Tom");
    // for (int i = 0; i < 51; ++i)
    //     c.attack("Tom");
    c = b;
    c.beRepaired(12);
    d.attack("Tom");
    d.guardGate();
}