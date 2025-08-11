#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string name;

public:
    Zombie(const std::string &str)
        : name(str) {};
    ~Zombie()
    {
        std::cout << name << " is destroyed" << std::endl;
    }

    void announce();
};

Zombie *newZombie(std::string name);

void randomChump(std::string name);

#endif