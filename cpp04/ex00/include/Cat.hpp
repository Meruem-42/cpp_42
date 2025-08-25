#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat()
    {
        std::cout << "Cat default constructor" << std::endl;
        type = "Cat";
    };
    Cat(const Cat &other)
        : Animal(other) { std::cout << "Cat copy constructor" << std::endl; };
    Cat &operator=(const Cat &other)
    {
        if (this != &other)
            Animal::operator=(other);
        std::cout << "Cat operator constructor" << std::endl;
        return (*this);
    }
    ~Cat() { std::cout << "Cat Destructor is called" << std::endl; };

    void makeSound() const;
};

#endif