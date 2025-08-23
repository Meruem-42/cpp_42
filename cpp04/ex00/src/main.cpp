/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:51:33 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/23 16:05:29 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    Animal *meta = new (std::nothrow) Animal();
    if (!meta)
        return (1);
    Animal *j = new (std::nothrow) Dog();
    if (!j)
        return (delete meta, 1);
    Animal *i = new (std::nothrow) Cat();
    if (!i)
        return (delete meta, delete j, 1);
    Animal *l = new (std::nothrow) WrongCat();
    if (!l)
        return (delete meta, delete j, delete l, 1);

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << l->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    l->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete l;

    return 0;
}