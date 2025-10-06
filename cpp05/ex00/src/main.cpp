/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:31:32 by aherlaud          #+#    #+#             */
/*   Updated: 2025/09/25 20:20:15 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main ()
{
    Bureaucrat a("Guy", 1);
    Bureaucrat c("Pierre", 30);
    Bureaucrat d("Paul", 50);
    Bureaucrat b("Bob", 150);

    try
    {
        c.incrementGrade();
        d.decrementGrade();
        // a.incrementGrade();
        // b.decrementGrade();
        // Bureaucrat e("Max", 151);
        Bureaucrat f("Jack", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << c << std::endl;
    std::cout << d << std::endl;
}