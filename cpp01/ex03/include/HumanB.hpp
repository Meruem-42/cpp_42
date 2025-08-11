#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "../include/Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *w;

public:
    HumanB(std::string str)
        : name(str), w(NULL) {};
    ~HumanB()
    {
        std::cout << "Human B class destroyed" << std::endl;
    }
    void setWeapon(Weapon& weapon);
    void attack();
};

#endif