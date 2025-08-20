#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(const std::string &n)
        : ClapTrap(n)
    {
        std::cout << "ScavTrap default constructor" << std::endl;
    };

    ScavTrap(ScavTrap &other)
        : ClapTrap(other)
    {
        std::cout << "ScavTrap copy constructor" << std::endl;
    }

    ScavTrap &operator=(ScavTrap &other)
    {
        std::cout << "ScavTrap operator constructor" << std::endl;
        if (this != &other)
            ClapTrap::operator=(other);
        return (*this);
    }

    ~ScavTrap(){ std::cout << "ScavTrap Destructor is called" << std::endl;}

    void attack(const std::string &target);
};

#endif