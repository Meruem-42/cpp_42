/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:08:06 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/12 19:09:35 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sed.hpp"

void ft_sed(const char *file_name, std::string to_find, std::string to_replace)
{
    std::string buffer;
    std::ifstream fd_in;
    std::ofstream fd_out;

    fd_in.open(file_name, std::ios::in);
    if (!(fd_in.is_open()))
    {
        std::cout << "can't open the file" << std::endl;
        return;
    }

    fd_out.open("text.replace", std::ios::out);
    if (!(fd_out.is_open()))
    {
        std::cout << "can't open the file" << std::endl;
        return;
    }

    while (!(fd_in.eof()))
    {
        getline(fd_in, buffer);
        for (int i = 0; buffer[i]; ++i)
        {
            i = buffer.find(to_find, i);
            if (i == -1)
                break;
            buffer.erase(i, to_find.length());
            buffer.insert(i, to_replace);
        }
        fd_out << buffer;
        if (!(fd_in.eof()))
            fd_out << std::endl;
    }
}