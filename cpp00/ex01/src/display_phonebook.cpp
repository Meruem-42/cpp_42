/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:44:45 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/08 17:19:11 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

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

void Contact::display_line_contact(int index)
{
    std::stringstream ss;

    ss << index;
    std::string str = ss.str();
    display_cell(str);
    std::cout << "|";
    display_cell(first_name);
    std::cout << "|";
    display_cell(last_name);
    std::cout << "|";
    display_cell(nickname);
    std::cout << std::endl;
}

void Phonebook::display_phonebook()
{
    display_title();
    for (int i = 0; i < number_of_contact; ++i)
        repertory[i].display_line_contact(i);
    std::cout << std::endl;
    find_and_display();
    std::cout << std::endl;
}