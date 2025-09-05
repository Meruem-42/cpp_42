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
#include "../include/Brain.hpp"

int main()
{
    // Dog a;
    // Dog b(a);
    // Cat *cat = new Cat();
    int N = 4;
    const Animal *array[N];
    // Dog c;
    // c = a;
    // Brain * other = a.get_brain();
    // other->set_idea(0, "lala");
    // other->set_idea(1, "lolo");

    // std::string *ideas = other->get_ideas();
    // for(int i = 0; ideas[i] != ""; ++i)
    //     std::cout << ideas[i] << std::endl;

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

    // delete cat;
    return 0;
}