#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *brain;

public:
    Dog()
    {
        std::cout << "Dog default constructor" << std::endl;
        type = "Dog";
        brain = new Brain();
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
    ~Dog()
    {
        delete brain;
        std::cout << "Dog Destructor is called" << std::endl;
    };

    void makeSound() const;
};

#endif