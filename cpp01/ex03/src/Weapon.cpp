/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:23:52 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/11 19:10:44 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

const std::string Weapon::getType()
{
    const std::string &ref = type;
    return (ref);
}

void Weapon::setType(std::string new_type)
{
    type = new_type;
}