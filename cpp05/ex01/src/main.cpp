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
#include "../include/Form.hpp"

int main ()
{
    Bureaucrat a("Guy", 10);
    Bureaucrat b("Bob", 150);
    Form test1("testform", 90, 60);
    Form test2("bestform", 90, 60);

    try
    {
        Bureaucrat a("", 10);
        test1.beSigned(b);
        // Form test3("test form", 150, 0);
    }
    catch (const Form::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;

    }

    std::cout << test1 << std::endl;
    test1.beSigned(a);
    std::cout << test1 << std::endl;

    b.signForm(test2);
    a.signForm(test2);
}