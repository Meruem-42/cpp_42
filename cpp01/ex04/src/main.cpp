/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:23:54 by meruem            #+#    #+#             */
/*   Updated: 2025/08/12 19:09:47 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sed.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
        return (std::cout << "wrong nmumber of arguments" << std::endl, 0);
    ft_sed(av[1], av[2], av[3]);
}