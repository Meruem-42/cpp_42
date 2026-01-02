#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cmath>
#include <vector>

class Span
{
private:
    std::vector<int> array_;
    unsigned int N_;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int num);
    void addNumber(std::vector<int>::iterator r_start, std::vector<int>::iterator r_end);
    int shortestSpan() const;
    int longestSpan() const;
    class IsFull : std::exception
    {
    public:
        const char *what() const throw();
    };

    class NotEnoughElement : std::exception
    {
    public:
        const char *what() const throw();
    };
};

#endif