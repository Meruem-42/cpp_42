#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

class NotFound : public std::exception
{
public:
    const char *what() const throw()
    {
        return ("Int not found");
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == value)
            return (it);
    }
    throw NotFound();
}

#endif