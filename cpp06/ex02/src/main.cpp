/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:44:53 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/16 15:11:27 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

int main ()
{
    Base *ptr;
    A a_ref;
    B b_ref;
    C c_ref;
    Base test;
    
    ptr = test.generate();
    test.identify(ptr);
    test.identify(a_ref);
    test.identify(b_ref);
    test.identify(c_ref);
    test.identify(test);
}