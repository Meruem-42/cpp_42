/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:25:48 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/12 22:24:46 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "DEBUG" << std::endl;
	harl.complain("DEBUG");
	std::cout << "INFO" << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR" << std::endl;
	harl.complain("ERROR");
	return (0);
}