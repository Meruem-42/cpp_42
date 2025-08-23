#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string ideas[100];

public:
    Brain() {};
    Brain(Brain &other)
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    };
    Brain &operator=(Brain &other)
    {
        if (this != &other)
        {
            for (int i = 0; i < 100; ++i)
                this->ideas[i] = other.ideas[i];
        }
        return (*this);
    }
    virtual ~Brain() {};
};

#endif