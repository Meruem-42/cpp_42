#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "../include/Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon w;

public:
    // HumanA() {};
    HumanA(std::string str, Weapon weapon)
        : name(str), w(weapon) {};
    void attack();
};

#endif