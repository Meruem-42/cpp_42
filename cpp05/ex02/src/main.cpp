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
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

int main ()
{
    Bureaucrat shrub("Shrub", 137);
    Bureaucrat robot("Robot", 45);
    Bureaucrat presi("Presi", 5);
    // AForm test("bad test", 4, 4);
    // Bureaucrat a("Bob", 150);

    ShrubberyCreationForm shru("presi_target");
    RobotomyRequestForm rob("robot_target");
    PresidentialPardonForm pre("presi_target");

    shru.beSigned(shrub);
    rob.beSigned(robot);
    pre.beSigned(presi);

    std::cout << shru << std::endl;
    std::cout << rob << std::endl;
    std::cout << pre << std::endl;

    shru.execute(shrub);
    rob.execute(robot);
    pre.execute(presi);

    // try
    // {
    //     shru.decrementGrade();
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