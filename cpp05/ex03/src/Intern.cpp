/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:16:57 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/03 15:16:58 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
    std::cout << "Intern Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    std::cout << "Intern Copy operator called" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm *CreateShrubbery(std::string const &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *CreateRobotomy(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}

AForm *CreatePresidential(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}


AForm *Intern::makeForm(std::string form_name, std::string target)
{
    std::string form_array[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm* (*Formptr[3])(std::string const &) = {&CreatePresidential, &CreateRobotomy, &CreateShrubbery};

    for(int i = 0; i < 3; ++i)
    {
        if(form_name == form_array[i])
        {
            std::cout << "Intern creates " << form_name << std::endl;
            return (Formptr[i](target));
        }
    }
    std::cout << "Intern can't find the form format " << form_name << std::endl;
    return (NULL);
}

