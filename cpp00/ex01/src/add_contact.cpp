/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:08:31 by meruem            #+#    #+#             */
/*   Updated: 2025/08/10 20:08:33 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"


void Phonebook::push_all()
{
    for(int i = 1; i < 8; ++i)
        repertory[i - 1] = repertory[i];
}

void Contact::fill_data_contact()
{
    std::cout << "First Name : ";
    std::cin >> first_name;
    protection_cin();
    std::cout << "Last Name : ";
    std::cin >> last_name;
    protection_cin();
    std::cout << "Nickname : ";
    std::cin >> nickname;
    protection_cin();
    std::cout << "Phone Number : ";
    std::cin >> phone_number;
    protection_cin();
    std::cout << "Darkest Secret : ";
    std::cin >> darkest_secret;
    protection_cin();
}

void Phonebook::add_contact()
{
    Contact c;

    c.fill_data_contact();
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