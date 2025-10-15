/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:45:12 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/15 18:57:04 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base::~Base()
{
}

Base * Base::generate(void)
{
    std::srand(std::time(NULL));

    int rand_num = std::rand() % 3;

    if(rand_num == 1)
        return (new A());
    else if (rand_num == 2)
        return (new B());
    else
        return (new C());
}

void Base::identify(Base* p)
{
    if(dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Simply a Base pointer" << std::endl;
}

void Base::identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(...)
    {
    }
    
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(...)
    {
    }

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(...)
    {
    }

    std::cout << "Just a Base reference" << std::endl;
}