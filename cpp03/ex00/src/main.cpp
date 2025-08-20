/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:51:33 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/20 16:15:36 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main()
{
    ClapTrap a("Tom");
    ClapTrap b("Michel");
    ClapTrap c("Lou");
    ClapTrap d(a);

    a.attack("Michel");
    b.takeDamage(5);
    b.beRepaired(5);
    b.takeDamage(10);
    b.attack("Tom");
    for (int i = 0; i < 11; ++i)
        c.attack("Tom");
    c = b;
    c.beRepaired(12);
    d.attack("Tom");
}