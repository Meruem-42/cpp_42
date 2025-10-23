/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:23:04 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/22 16:23:06 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

int main()
{
    Array<int> test1(2);
    Array<int> test2(5);

    std::cout << "TEST ARRAY SIZE" << "\n\n";
    for (unsigned int i = 0; i < test1.size(); ++i)
    {
        std::cout << test1[i] << std::endl;
    }

    std::cout << "COPY CONSTRUCTOR TEST" << "\n\n";
    Array<int> test3(test2);
    for (unsigned int i = 0; i < test3.size(); ++i)
    {
        std::cout << test3[i] << std::endl;
    }

    std::cout << "= OPERATOR TEST" << "\n\n";
    test3 = test1;
    for (unsigned int i = 0; i < test3.size(); ++i)
    {
        std::cout << test3[i] << std::endl;
    }

    std::cout << "OUT OF BOUNDS TEST" << "\n\n";
    try
    {
        std::cout << test3[10] << std::endl;
    }
    catch (const Array<int>::OutOfBounds &e)
    {
        std::cout << "Out of bounds" << std::endl;
    }
}