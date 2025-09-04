#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat()
    {
        std::cout << "WrongCat default constructor" << std::endl;
        type = "WrongCat";
    };
    WrongCat(const WrongCat &other)
        : WrongAnimal(other) { std::cout << "WrongCat copy constructor" << std::endl; };
    WrongCat &operator=(const WrongCat &other)
    {
        if (this != &other)
            WrongAnimal::operator=(other);
        std::cout << "WrongCat operator constructor" << std::endl;
        return (*this);
    }
    ~WrongCat() { std::cout << "WrongCat Destructor is called" << std::endl; };
};

#endif