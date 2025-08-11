#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string weapon_name)
        : type(weapon_name) {};
    ~Weapon()
    {
        std::cout << "Weapon class destroyed" << std::endl;
    }
    const std::string getType();
    void setType(std::string new_type);
};

#endif