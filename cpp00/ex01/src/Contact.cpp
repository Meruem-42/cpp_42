/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:42:55 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/19 17:01:56 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

void Contact::set_contact()
{
    while (first_name.length() == 0 || is_empty(first_name) == 1)
    {
        std::cout << "First Name : ";
        getline(std::cin, first_name);
    }
    if (protection_cin() == 1)
        return;
    while (last_name.length() == 0 || is_empty(last_name) == 1)
    {
        std::cout << "Last Name : ";
        getline(std::cin, last_name);
    }
    if (protection_cin() == 1)
        return;
    while (nickname.length() == 0 || is_empty(nickname) == 1)
    {
        std::cout << "Nickame : ";
        getline(std::cin, nickname);
    }
    if (protection_cin() == 1)
        return;
    while (phone_number.length() == 0 || is_empty(phone_number) == 1)
    {
        std::cout << "Phone number : ";
        getline(std::cin, phone_number);
    }
    if (protection_cin() == 1)
        return;
    while (darkest_secret.length() == 0 || is_empty(darkest_secret) == 1)
    {
        std::cout << "Darkest Secret : ";
        getline(std::cin, darkest_secret);
    }
}

std::string Contact::get_first_name()
{
    return (first_name);
}

std::string Contact::get_last_name()
{
    return (last_name);
}

std::string Contact::get_nickname()
{
    return (nickname);
}

std::string Contact::get_phone_number()
{
    return (phone_number);
}

std::string Contact::get_darkest_secret()
{
    return (darkest_secret);
}
