/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:51:33 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/21 18:29:11 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main()
{
    FragTrap a("Tom");
    FragTrap b("Michel");
    FragTrap c("Lou");
    FragTrap d(a);

    a.attack("Michel");
    b.takeDamage(50);
    b.beRepaired(50);
    b.takeDamage(100);
    b.attack("Tom");
    for (int i = 0; i < 101; ++i)
        c.attack("Tom");
    c = b;
    c.beRepaired(12);
    d.attack("Tom");
    d.highFivesGuys();
}