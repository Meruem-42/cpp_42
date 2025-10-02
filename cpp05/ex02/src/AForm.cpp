/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:50:25 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/01 14:51:07 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(std::string name, int grade_sign, int grade_exec)
    : name_(name), 
        sign_(false), 
        grade_sign_(grade_sign), 
        grade_exec_(grade_exec)
{
    if(grade_sign < 1 || grade_exec < 1)
        throw AForm::GradeTooHighException();
    if(grade_exec > 150 || grade_sign > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
    : name_(other.name_),
      sign_(other.sign_),
      grade_sign_(other.grade_sign_),
      grade_exec_(other.grade_exec_)
{
    std::cout << "AForm copy constructor called" << std::endl;
}
AForm &AForm::operator=(const AForm& other)
{
    std::cout << "AForm copy operator constructor called" << std::endl;
    this->sign_ = other.sign_;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return (name_);
}

bool AForm::getSign() const
{
    return (sign_);
}

int AForm::getGradeSign() const
{
    return (grade_sign_);
}

int AForm::getGradeExec() const
{
    return (grade_exec_);
}

void AForm::beSigned(Bureaucrat& c)
{
    if(c.getGrade() <= grade_sign_)
        sign_ = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > grade_exec_)
        throw AForm::GradeTooLowException();
    else if (this->sign_ != true)
        throw AForm::FormNotSignedException();
    else
        executeAction();
}

void AForm::executeAction() const
{
}


const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed");
}


std::ostream &operator<<(std::ostream &cout, const AForm& other)
{
    if (other.getSign())
        return (cout << other.getName() << ", Form can be signed by Bureaucrat of grade " << other.getGradeSign() << " and can be executed by Bureaucrat of the grade " << other.getGradeExec() << ". This Form is signed.");
    else
        return (cout << other.getName() << ", Form can be signed by Bureaucrat of grade " << other.getGradeSign() << " and can be executed by Bureaucrat of the grade " << other.getGradeExec() << ". This Form is not signed.");

}
