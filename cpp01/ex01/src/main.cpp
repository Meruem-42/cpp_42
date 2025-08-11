/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:31:22 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/11 17:53:10 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main()
{
    Zombie *horde;
    int N;

    N = 3;

    horde = zombieHorde(N, "Didier");
    if (!horde)
        return (1);
    for (int i = 0; i < N; ++i)
        horde[i].announce();
    delete[] horde;
    return (1);
}