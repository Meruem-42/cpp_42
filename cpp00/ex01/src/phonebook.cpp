/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:08:47 by meruem            #+#    #+#             */
/*   Updated: 2025/08/11 13:16:37 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

void initial_prompt()
{
    std::cout << "Please choose between the 3 choices :" << std::endl;
    std::cout << "-ADD: save a new contact" << std::endl;
    std::cout << "-SEARCH: display a specific contact" << std::endl;
    std::cout << "-EXIT: quit and erase the phonebook" << std::endl;
    std::cout << std::endl;
    std::cout << "Your choice : ";
}

void detect_command(Phonebook *phone, std::string choice)
{
    if (choice == "ADD")
        (*phone).add_contact();
    else if (choice == "SEARCH")
        (*phone).display_phonebook();
    else if (choice == "EXIT")
        exit(0);
}

int main()
{
    std::string choice;
    Phonebook phone;

    while (1)
    {
        initial_prompt();
        std::cin >> choice;
        protection_cin();
        std::cout << std::endl;
        detect_command(&phone, choice);
        std::cout << std::endl;
    }
    return (0);
}
