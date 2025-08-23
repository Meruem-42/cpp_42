#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>

#include "Animal.hpp"

class WrongCat : public Animal
{
public:
    WrongCat()
    {
        std::cout << "WrongCat default constructor" << std::endl;
        type = "WrongCat";
    };
    WrongCat(WrongCat &other)
        : Animal(other) { std::cout << "WrongCat copy constructor" << std::endl; };
    WrongCat &operator=(WrongCat &other)
    {
        std::cout << "WrongCat operator constructor" << std::endl;
        if (this != &other)
            Animal::operator=(other);
        return (*this);
    }
    ~WrongCat() { std::cout << "WrongCat Destructor is called" << std::endl; };

    void makeSound();
};

#endif