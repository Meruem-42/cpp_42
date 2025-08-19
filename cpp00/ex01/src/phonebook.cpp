/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:08:47 by meruem            #+#    #+#             */
/*   Updated: 2025/08/17 18:18:50 by meruem           ###   ########.fr       */
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

int detect_command(Phonebook *phone, std::string choice)
{
    if (choice == "ADD")
        (*phone).add_contact();
    else if (choice == "SEARCH")
        (*phone).display_phonebook();
    else if (choice == "EXIT")
        return (1);
    return (0);
}

int main()
{
    std::string choice;
    Phonebook phone;

    while (!(std::cin.eof()))
    {
        initial_prompt();
        getline(std::cin, choice);
        std::cout << std::endl;
        if (detect_command(&phone, choice) == 1)
            return (0);
        std::cout << std::endl;
    }
    return (0);
}
