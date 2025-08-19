/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:08:47 by meruem            #+#    #+#             */
/*   Updated: 2025/08/19 19:23:34 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Phonebook.hpp"

Contact *Phonebook::get_repertory()
{
    return (repertory);
}

int Phonebook::get_nbcontact()
{
    return (number_of_contact);
}

void Phonebook::push_all()
{
    for (int i = 1; i < 8; ++i)
        repertory[i - 1] = repertory[i];
}

void Phonebook::add_contact()
{
    Contact c;

    c.set_contact();
    if (number_of_contact != 8)
    {
        repertory[number_of_contact] = c;
        ++number_of_contact;
    }
    else
    {
        push_all();
        repertory[number_of_contact - 1] = c;
    }
}
