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

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    std::cout << "TEST NUMBER FOUND" << "\n\n";
    try
    {
        easyfind(v, 20);
        std::cout << "number found" << std::endl;
    }
    catch (const NotFound &e)
    {
        std::cout << "number not found" << std::endl;
    }

    std::cout << "\nTEST NUMBER NOT FOUND" << "\n\n";
    try
    {
        easyfind(v, 40);
        std::cout << "number found" << std::endl;
    }
    catch (const NotFound &e)
    {
        std::cout << "number not found" << std::endl;
    }
}