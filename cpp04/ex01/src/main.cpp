/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:51:33 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/25 22:04:29 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    const Dog a;
    Dog b(a);
    int N = 4;
    const Animal *array[N];

    for (int i = 0; i < N; ++i)
    {
        if (i < (N / 2))
            array[i] = new Dog();
        else
            array[i] = new Cat();
    }

    for (int i = 0; i < N; ++i)
        array[i]->makeSound();

    for (int i = 0; i < N; ++i)
        delete array[i];

    // delete j; // should not create a leak
    // delete i;
    return 0;
}