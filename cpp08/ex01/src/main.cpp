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

#include "../include/Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);

    std::cout << "TEST SHORTEST SPAN WITH NOT ENOUGH ELEMENT\n";

    try
    {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const Span::NotEnoughElement &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "TEST LONGEST SPAN WITH NOT ENOUGH ELEMENT\n";
    try
    {
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const Span::NotEnoughElement &e)
    {
        std::cout << e.what() << std::endl;
    }

    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "TEST ADD NUMBER WHEN VECTOR FULL\n";
    try
    {
        sp.addNumber(42);
    }
    catch (const Span::IsFull &e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "TEST WORKING SHORTES AND LONGEST SPAN\n";
    std::cout << "shortest span is : " << sp.shortestSpan() << std::endl;
    std::cout << "longest span is : " << sp.longestSpan() << std::endl;

    std::cout << "TEST ADD NUMBER WITH A RANGE OF ITERATORS\n";
    try
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        Span span(4);
        span.addNumber(v.begin(), v.end());
        std::cout << "shortest span is : " << span.shortestSpan() << std::endl;
        std::cout << "longest span is : " << span.longestSpan() << std::endl;
    }
    catch (const Span::IsFull &e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}