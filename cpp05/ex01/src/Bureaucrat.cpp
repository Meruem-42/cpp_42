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
#include "../include/Form.hpp"

Bureaucrat::Bureaucrat(std::string n, int g)
    : name(n)
{
    std::cout << "Default Bureaucrat constructor called" << std::endl;
    if(g > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        grade = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy operator called" << std::endl;
    this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::incrementGrade()
{
    if(grade -1 < 1)
        throw Bureaucrat::GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade()
{
    if(grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    ++grade;
}

void Bureaucrat::signForm(Form& c)
{
    try
    {
        c.beSigned(*this);    
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cout << this->name << " couldn't sign " << c.getName() << " because " << e.what() << std::endl;
    }
    std::cout << this->name << " signed " << c.getName() << std::endl;
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &cout, const Bureaucrat &b)
{
    return (cout << b.getName() << ", bureaucrat grade " << b.getGrade() << ".");
}