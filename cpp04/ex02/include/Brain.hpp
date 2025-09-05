#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string ideas[100];

public:
    Brain() { std::cout << "Brain default constructor" << std::endl; };
    Brain(const Brain &other)
    {
        std::cout << "Brain copy constructor" << std::endl;
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    };
    Brain &operator=(const Brain &other)
    {
        std::cout << "Brain operator constructor" << std::endl;
        if (this != &other)
        {
            for (int i = 0; i < 100; ++i)
                this->ideas[i] = other.ideas[i];
        }
        return (*this);
    }
    ~Brain() { std::cout << "Brain Destructor is called" << std::endl; };

    std::string *get_ideas();
    void set_idea(int idea_num, std::string idea);
};

#endif