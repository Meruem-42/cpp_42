#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap(const std::string name)
        : ClapTrap(name) { std::cout << "FragTrap default constructor" << std::endl; };
    FragTrap(FragTrap &other)
        : ClapTrap(other) { std::cout << "FragTrap copy constructor" << std::endl; };
    FragTrap &operator=(FragTrap &other)
    {
        std::cout << "FragTrap operator constructor" << std::endl;
        if (this != &other)
            ClapTrap::operator=(other);
        return (*this);
    }
    ~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; };

    void highFivesGuys(void);
};

#endif