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

void print_elem_array(int elem)
{
    std::cout << elem << std::endl;
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    iter(array, 5, print_elem_array);
}