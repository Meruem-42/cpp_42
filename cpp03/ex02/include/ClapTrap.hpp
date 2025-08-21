#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string name;
    int hit_points;
    int energy_points;
    int attack_damage;

public:
    ClapTrap(const std::string &n)
        : name(n)
    {
        std::cout << "ClapTrap default constructor" << std::endl;
        hit_points = 100;
        energy_points = 100;
        attack_damage = 30;
    };

    ClapTrap(ClapTrap &other)
    {
        std::cout << "ClapTrap copy constructor" << std::endl;
        *this = other;
    }

    ClapTrap &operator=(ClapTrap &other)
    {
        std::cout << "ClapTrap operator constructor" << std::endl;
        if (this != &other)
        {
            name = other.name;
            hit_points = other.hit_points;
            energy_points = other.energy_points;
            attack_damage = other.attack_damage;
        }
        return (*this);
    }

    ~ClapTrap() { std::cout << "ClapTrap Destructor is called" << std::endl; }

    virtual void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif