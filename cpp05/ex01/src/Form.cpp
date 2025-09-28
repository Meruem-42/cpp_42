/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:24:29 by meruem            #+#    #+#             */
/*   Updated: 2025/09/26 22:24:29 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(std::string& n, int gs, int ge)
    : name(n), grade_sign(gs), grade_exec(ge)
{
    if(grade_sign < 1 || grade_exec < 1)
        throw Form::GradeTooHighException();
    if(grade_exec > 150 || grade_sign > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form Default constructor called" << std::endl;
    sign = 0;
}

Form::Form(const Form& other)
    : name(other.name), grade_sign(other.grade_sign), grade_exec(other.grade_exec)
{
    // std::cout << "Form Copy constructor called" << std::endl;
    // if(other.grade_sign < 1 || other.grade_exec < 1)
    //     throw Form::GradeTooHighException();
    // if(other.grade_exec > 150 || other.grade_sign > 150)
    //     throw Form::GradeTooLowException();
    sign = other.sign;
}

Form &Form::operator=(const Form& other)
{
    std::cout << "Form Copy operator constructor called" << std::endl;
    this->sign = other.sign;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
    return (name);
}

bool Form::getSign() const
{
    return (sign);
}

int Form::getGradeSign() const
{
    return (grade_sign);
}

int Form::getGradeExec() const
{
    return (grade_exec);
}

void Form::beSigned(Bureaucrat& c)
{
    if(c.getGrade() <= grade_sign)
        sign = true;
    else
        throw Form::GradeTooLowException();

}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream& cout, const Form& other)
{
    if (other.getSign())
        return (cout << other.getName() << ", Form can be signed by Bureaucrat of grade " << other.getGradeSign() << " and can be executed by Bureaucrat of the grade " << other.getGradeExec() << ". This Form is signed.");
    else
        return (cout << other.getName() << ", Form can be signed by Bureaucrat of grade " << other.getGradeSign() << " and can be executed by Bureaucrat of the grade " << other.getGradeExec() << ". This Form is not signed.");
}

