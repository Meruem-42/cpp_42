#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string name;
    int hit_points;
    int energy_points;
    int attack_damage;

public:
    ClapTrap(const std::string &n)
        : name(n)
    {
        std::cout << "Default constructor called" << std::endl;
        hit_points = 10;
        energy_points = 10;
        attack_damage = 0;
    };

    ClapTrap(ClapTrap &other)
    {
        std::cout << "Copy constructor called" << std::endl;
        *this = other;
    }

    ClapTrap &operator=(ClapTrap &other)
    {
        std::cout << "Copy constructor operator called" << std::endl;
        if (this != &other)
        {
            name = other.name;
            hit_points = other.hit_points;
            energy_points = other.energy_points;
            attack_damage = other.attack_damage;
        }
        return (*this);
    }

    ~ClapTrap() { std::cout << "Destructor is called" << std::endl; }

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif