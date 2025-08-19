/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_phonebook.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:44:45 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/19 19:23:12 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/global.hpp"
#include "../include/Contact.hpp"
#include "../include/Phonebook.hpp"

void display_cell(std::string str)
{
    for (int i = str.length(); i < 10; ++i)
        std::cout << " ";
    for (int i = 0; str[i]; ++i)
    {
        if (i == 9 && str[i])
        {
            std::cout << ".";
            return;
        }
        else
            std::cout << str[i];
    }
}

void display_title()
{
    display_cell("index");
    std::cout << "|";
    display_cell("first name");
    std::cout << "|";
    display_cell("last name");
    std::cout << "|";
    display_cell("nickname");
    std::cout << std::endl;
}

void display_line_contact(int index, Contact c)
{
    std::stringstream ss;

    ss << index;
    std::string str = ss.str();
    display_cell(str);
    std::cout << "|";
    display_cell(c.get_first_name());
    std::cout << "|";
    display_cell(c.get_last_name());
    std::cout << "|";
    display_cell(c.get_nickname());
    std::cout << std::endl;
}

void display_phonebook(Phonebook p)
{
    Contact *c_array;

    c_array = p.get_repertory();
    display_title();
    for (int i = 0; i < p.get_nbcontact(); ++i)
        display_line_contact(i, c_array[i]);
    std::cout << std::endl;
    find_and_display(p);
    std::cout << std::endl;
}