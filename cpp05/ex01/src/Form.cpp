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

Form::Form(std::string const& n, int gs, int ge)
    : name_(n),  sign_(0), grade_sign_(gs), grade_exec_(ge)
{
    std::cout << "Form Default constructor called" << std::endl;
    if(grade_sign_ < 1 || grade_exec_ < 1)
        throw Form::GradeTooHighException();
    if(grade_exec_ > 150 || grade_sign_ > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
    : name_(other.name_), sign_(other.sign_), grade_sign_(other.grade_sign_), grade_exec_(other.grade_exec_)
{
    std::cout << "Form Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form& other)
{
    std::cout << "Form Copy operator called" << std::endl;
    this->sign_ = other.sign_;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
    return (name_);
}

bool Form::getSign() const
{
    return (sign_);
}

int Form::getGradeSign() const
{
    return (grade_sign_);
}

int Form::getGradeExec() const
{
    return (grade_exec_);
}

void Form::beSigned(Bureaucrat& c)
{
    if(c.getGrade() <= grade_sign_)
        sign_ = true;
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
        return (cout << other.getName() << " Form can be signed by Bureaucrat of grade " << other.getGradeSign() << " and can be executed by Bureaucrat of the grade " << other.getGradeExec() << ". This Form is signed.");
    else
        return (cout << other.getName() << " Form can be signed by Bureaucrat of grade " << other.getGradeSign() << " and can be executed by Bureaucrat of the grade " << other.getGradeExec() << ". This Form is not signed.");
}
