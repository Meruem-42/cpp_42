#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog()
    {
        std::cout << "Dog default constructor" << std::endl;
        type = "Dog";
    };
    Dog(Dog &other)
        : Animal(other) { std::cout << "Dog copy constructor" << std::endl; };
    Dog &operator=(Dog &other)
    {
        std::cout << "Dog operator constructor" << std::endl;
        if (this != &other)
            Animal::operator=(other);
        return (*this);
    }
    ~Dog() { std::cout << "Dog Destructor is called" << std::endl; };

    void makeSound();
};

#endif