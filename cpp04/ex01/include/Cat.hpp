#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *brain;

public:
    Cat()
    {
        std::cout << "Cat default constructor" << std::endl;
        type = "Cat";
        brain = new Brain();
    };
    Cat(Cat &other)
        : Animal(other) { std::cout << "Cat copy constructor" << std::endl; };
    Cat &operator=(Cat &other)
    {
        std::cout << "Cat operator constructor" << std::endl;
        if (this != &other)
            Animal::operator=(other);
        return (*this);
    }
    ~Cat()
    {
        delete brain;
        std::cout << "Cat Destructor is called" << std::endl;
    };

    void makeSound() const;
};

#endif