#include "../include/Span.hpp"

Span::Span()
    : N_(0)
{
}

Span::Span(unsigned int N)
    : N_(N)
{
}

Span::Span(const Span &other)
    : N_(other.N_)
{
    for (unsigned int i = 0; i < N_; ++i)
        array_[i] = other.array_[i];
}

Span &Span::operator=(const Span &other)
{
    this->N_ = other.N_;
    for (unsigned int i = 0; i < N_; ++i)
        this->array_[i] = other.array_[i];
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
    if (array_.size() == N_)
        throw IsFull();
    array_.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator r_start, std::vector<int>::iterator r_end)
{
    for(std::vector<int>::iterator it = r_start; it != r_end; ++it)
    {
        if (array_.size() == N_)
            throw IsFull();
        array_.push_back(*it);
    }
}


int Span::shortestSpan() const
{
    if (array_.size() < 2)
        throw NotEnoughElement();
    int short_span;
    for (unsigned long i = 0; i < array_.size(); ++i)
        for (unsigned long j = i + 1; j < array_.size(); ++j)
        {
            if (i == 0)
                short_span = abs(array_[i] - array_[j]);
            if (abs(array_[i] - array_[j]) < short_span)
                short_span = abs(array_[i] - array_[j]);
        }
    return short_span;
}

int Span::longestSpan() const
{
    if (array_.size() < 2)
        throw NotEnoughElement();
    int min = array_[0];
    int max = array_[0];
    for (unsigned long i = 0; i < array_.size(); ++i)
    {
        if (array_[i] < min)
            min = array_[i];
    }

    for (unsigned long i = 0; i < array_.size(); ++i)
    {
        if (array_[i] > max)
            max = array_[i];
    }
    return max - min;
}

const char *Span::IsFull::what() const throw()
{
    return ("Span is full");
}

const char *Span::NotEnoughElement::what() const throw()
{
    return ("Not enough element in the vector");
}