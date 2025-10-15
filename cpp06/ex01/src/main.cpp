/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:39:15 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/15 15:39:16 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"
#include "../include/Serializer.hpp"

int main()
{
    uintptr_t int_test;
    Data *ptr_test;
    
    ptr_test = new Data(10);
    int_test = Serializer::serialize(ptr_test);
    if(ptr_test == Serializer::deserialize(int_test))
        std::cout << "SUCCESS" << std::endl;
    else
        std::cout << "FAILURE" << std::endl;

    delete ptr_test;
}