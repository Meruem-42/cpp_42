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

#include "../include/AForm.hpp"
#include "../include/Intern.hpp"

int main ()
{
    const Intern someRandomIntern;
    AForm* rrf;
    AForm* ppf;
    AForm* failf;

    AForm* scf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    failf = someRandomIntern.makeForm("bad form", "Bender");


    delete rrf;
    delete ppf;
    delete scf;
}