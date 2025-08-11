#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "../include/Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon& w;

public:
    HumanA(std::string str, Weapon& weapon)
        : name(str), w(weapon) {};
    ~HumanA()
    {
        std::cout << "Human A class destroyed" << std::endl;
    }
    void attack();
};

#endif