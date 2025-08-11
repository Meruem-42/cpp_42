#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string name;

public:
    Zombie() {};
    Zombie(const std::string &str)
        : name(str) {};
    ~Zombie()
    {
        std::cout << name << " is destroyed" << std::endl;
    }
    void set_name(std::string str);
    void announce();
};

Zombie *zombieHorde(int N, std::string name);

#endif