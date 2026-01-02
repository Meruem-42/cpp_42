/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:23:20 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/24 18:23:21 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <vector>
#include <deque>

int main()
{
    std::vector<int> test1;
    test1.push_back(10);
    test1.push_back(20);
    std::deque<int> test2;
    test2.push_back(30);
    test2.push_back(50);

    std::cout << "TEST NUMBER FOUND" << "\n\n";
    try
    {
        easyfind(test1, 20);
        std::cout << "number found" << std::endl;
    }
    catch (const NotFound &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTEST NUMBER NOT FOUND" << "\n\n";
    try
    {
        easyfind(test2, 20);
        std::cout << "number found" << std::endl;
    }
    catch (const NotFound &e)
    {
        std::cout << e.what() << std::endl;
    }
}