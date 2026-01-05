#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFound : public std::exception
{
public:
    const char *what() const throw()
    {
        return ("number not found");
    }
};

#include "../include/easyfind.tpp"

#endif