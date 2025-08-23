#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal() { std::cout << "Animal default constructor" << std::endl; };
    Animal(Animal &other)
        : type(other.type) { std::cout << "Animal copy constructor" << std::endl; };
    Animal &operator=(Animal &other)
    {
        std::cout << "Animal operator constructor" << std::endl;
        if (this != &other)
            this->type = other.type;
        return (*this);
    }
    virtual ~Animal() { std::cout << "Animal Destructor is called" << std::endl; };

    std::string getType() const;
    virtual void makeSound() const;
};

#endif