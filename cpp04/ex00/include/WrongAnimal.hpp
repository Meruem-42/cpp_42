#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal() { std::cout << "WrongAnimal default constructor" << std::endl; };
    WrongAnimal(const WrongAnimal &other)
        : type(other.type) { std::cout << "WrongAnimal copy constructor" << std::endl; };
    WrongAnimal &operator=(const WrongAnimal &other)
    {
        std::cout << "WrongAnimal operator constructor" << std::endl;
        if (this != &other)
            this->type = other.type;
        return (*this);
    }
    virtual ~WrongAnimal() { std::cout << "WrongAnimal Destructor is called" << std::endl; };

    std::string getType() const;
    void makeSound() const;
};

#endif