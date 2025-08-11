/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:45:49 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/08 18:08:25 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

void Contact::display_contact()
{
    std::cout << "First Name : " << first_name << std::endl;
    std::cout << "Last Name : " << last_name << std::endl;
    std::cout << "Nickname : " << nickname << std::endl;
    std::cout << "Phone Number : " << phone_number << std::endl;
    std::cout << "Darkest Secret : " << darkest_secret << std::endl;
}

void Phonebook::find_and_display()
{
    std::string choice;
    int index_chosen = -1;

    if (number_of_contact == 0)
    {
        std::cout << "phonebook is empty" << std::endl;
        return;
    }
    while (1)
    {
        if (index_chosen >= 0 && index_chosen <= 7 && index_chosen >= number_of_contact)
            std::cout << "index can't be found try again" << std::endl;
        std::cout << "Choose the index of the contact you want to display :";
        std::cin >> choice;
        protection_cin();
        if (choice.length() == 1)
        {
            if (choice[0] >= '0' && choice[0] <= '7')
            {
                std::stringstream ss(choice);
                ss >> index_chosen;
                if (index_chosen >= number_of_contact)
                    continue;
                for (int i = 0; i < index_chosen; ++i)
                    ;
                repertory[index_chosen].display_contact();
                return;
            }
        }
        std::cout << "index can't be found try again between 0 and 7" << std::endl;
    }
}