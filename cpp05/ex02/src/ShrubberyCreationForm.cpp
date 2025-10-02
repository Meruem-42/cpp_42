/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:50:55 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/01 14:50:58 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target_(target)
{
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target_(other.target_)
{
    std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm Copy operator called" << std::endl;
    AForm::operator=(other);
    this->target_ = other.target_;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
    std::string test = target_ + "_shrubbery";
    std::ofstream outfile(test.c_str());
    if(!outfile)
        throw ShrubberyCreationForm::FileErrorException();

    outfile <<
    "      ccee88oo\n"
    "   C8O8O8Q8PoOb o8oo\n"
    "  dOB69QO8PdUOpugoO9bD\n"
    " CgggbU8OU qOp qOdoUOdcb\n"
    "     6OuU  /p u gcoUodpP\n"
    "       \\\\//  /douUP\n"
    "         \\/////\n"
    "          |||\n"
    "          |||\n"
    "          |||\n";

    outfile.close();
}

const char *ShrubberyCreationForm::FileErrorException::what() const throw()
{
    return ("Failed to open file");
}



