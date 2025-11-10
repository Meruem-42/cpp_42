#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <cmath>

class Span
{
private:
    int *array_;
    unsigned int N_;
    unsigned int fill_number_;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();


    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;
    class IsFull : std::exception
    {
    public:
        const char *why() const throw();
    };

    class NotEnoughElement : std::exception
    {
    public:
        const char *why() const throw();
    };
};

#endif