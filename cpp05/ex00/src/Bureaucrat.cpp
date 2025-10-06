/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:31:28 by aherlaud          #+#    #+#             */
/*   Updated: 2025/09/25 20:22:44 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string n, int g)
    : name_(n), grade_(g)
{
    std::cout << "Default Bureaucrat constructor called" << std::endl;
    if(g > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (g < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_), grade_(other.grade_)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy operator called" << std::endl;
    this->grade_ = other.grade_;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (name_);
}

int Bureaucrat::getGrade() const
{
    return (grade_);
}

void Bureaucrat::incrementGrade()
{
    if(grade_ -1 < 1)
        throw Bureaucrat::GradeTooHighException();
    --grade_;
}

void Bureaucrat::decrementGrade()
{
    if(grade_ + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    ++grade_;
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("grade too low");
}

std::ostream &operator<<(std::ostream &cout, const Bureaucrat &b)
{
    return (cout << b.getName() << ", bureaucrat grade " << b.getGrade() << ".");
}