/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_contact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:45:49 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/19 19:25:44 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/global.hpp"
#include "../include/Phonebook.hpp"

void display_contact(Contact c)
{
    std::cout << "First Name : " << c.get_first_name() << std::endl;
    std::cout << "Last Name : " << c.get_last_name() << std::endl;
    std::cout << "Nickname : " << c.get_nickname() << std::endl;
    std::cout << "Phone Number : " << c.get_phone_number() << std::endl;
    std::cout << "Darkest Secret : " << c.get_darkest_secret() << std::endl;
}

void find_and_display(Phonebook p)
{
    std::string choice;
    Contact *temp = p.get_repertory();
    int index_chosen = -1;

    if (p.get_nbcontact() == 0)
    {
        std::cout << "phonebook is empty" << std::endl;
        return;
    }
    std::cout << "Choose the index of the contact you want to display :";
    getline(std::cin, choice);
    if (choice.length() == 1)
    {
        if (choice[0] >= '0' && choice[0] <= '7')
        {
            std::stringstream ss(choice);
            ss >> index_chosen;
            if (index_chosen >= p.get_nbcontact())
                return;
            for (int i = 0; i < index_chosen; ++i)
                ;
            display_contact(temp[index_chosen]);
        }
    }
}