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
    Dog(const Dog &other)
        : Animal(other)
    {
        std::cout << "Dog copy constructor" << std::endl;
        brain = new Brain(*(other.brain));
    };

    Dog &operator=(const Dog &other)
    {
        if (this != &other)
        {
            delete brain;
            Animal::operator=(other);
            brain = new Brain(*(other.brain));
        }
        std::cout << "Dog operator constructor" << std::endl;
        return (*this);
    }
    ~Dog()
    {
        delete brain;
        std::cout << "Dog Destructor is called" << std::endl;
    };

    void makeSound() const;
    Brain *get_brain();    
};

#endif