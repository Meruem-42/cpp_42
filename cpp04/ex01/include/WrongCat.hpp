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
        if (this != &other)
            Animal::operator=(other);
        std::cout << "WrongCat operator constructor" << std::endl;
        return (*this);
    }
    ~WrongCat() { std::cout << "WrongCat Destructor is called" << std::endl; };

    void makeSound() const;
};

#endif