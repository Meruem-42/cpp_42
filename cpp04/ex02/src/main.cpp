/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:51:33 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/25 23:26:23 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

int main()
{
    // const Animal yo;
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    j->makeSound();
    i->makeSound();

    delete j; // should not create a leak
    delete i;
    return 0;
}