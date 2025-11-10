#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

class Span
{
private:
    int *array_;
    unsigned int N_;
    int fill_number_;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();


    void addNumber();
    class IsFull : std::exception
    {
    public:
        const char *why() const throw();
    };
};

#endif