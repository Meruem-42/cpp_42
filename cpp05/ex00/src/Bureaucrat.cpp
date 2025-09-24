/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:31:28 by aherlaud          #+#    #+#             */
/*   Updated: 2025/09/24 14:31:37 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string n, int g)
    : name(n)
{
    std::cout << "Default Bureaucrat constructor called" << std::endl;
    if(g < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (g > 150)
        throw Bureaucrat::GradeTooHighException();
    else
        grade = g;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Bureaucrat destructor called" << std::endl;
}

const std::string Bureaucrat::getName()
{
    return (name);
}

const int Bureaucrat::getGrade()
{
    return (grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}