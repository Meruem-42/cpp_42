/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:58:10 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/11 17:53:17 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde;

    if (N < 0)
        return (NULL);
    horde = new (std::nothrow) Zombie[N];
    if (!horde)
        return (NULL);
    for (int i = 0; i < N; ++i)
        horde[i].set_name(name);

    return (horde);
}