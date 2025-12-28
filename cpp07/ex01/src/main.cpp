/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:13:31 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/21 16:13:32 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

void print(int elem)
{
    std::cout << elem << std::endl;
}

void increment(int& x)
{
    ++x;
}

int main()
{
    const int array[5] = {1, 2};
    int array_bis[5] = {1, 2, 3};
    std::cout << "TEST PRINT FUNCTION" << std::endl;
    iter(array, 2, print);
    iter(array_bis, 3, print);
    std::cout << "TEST PRINT FUNCTION TEMPLATE" << std::endl;
    // iter(array, 2, increment_temp<int>);
    iter(array_bis, 3, increment_temp<int>);
    iter(array, 2, print_temp<const int>);
    iter(array_bis, 3, print_temp<int>);
    std::cout << "TEST FUNCTION NON CONST" << std::endl;
    // iter(array, 2, increment);
    iter(array_bis, 3, increment);
    iter(array_bis, 3, print);
}