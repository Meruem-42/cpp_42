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
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"

int main ()
{
    Bureaucrat a("Guy", 10);
    Intern test;
    // Bureaucrat b("Bob", 151);
    // Bureaucrat c(b);
    AForm *ptr = test.makeForm("ShrubberyCreationForm", "home");

    
    std::cout << "name of the form : " << ptr->getName() << std::endl; 
    std::cout << "grade sign of the form : " << ptr->getGradeSign() << std::endl; 
    std::cout << "grade exec of the form : " << ptr->getGradeExec() << std::endl;

    delete ptr;
    // ShrubberyCreationForm test("lala");

    // test.beSigned(a);
    // std::cout << test.getGradeExec() << std::endl;

    // test.execute(a);
    // try
    // {
    //     b.decrementGrade();
    // }
    // catch (const Bureaucrat::GradeTooHighException& e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException& e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // std::cout << b << std::endl;
    // std::cout << c << std::endl;
}