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
        array_.push_back(other.array_[i]);
}

Span &Span::operator=(const Span &other)
{
    this->N_ = other.N_;
    for (unsigned int i = 0; i < N_; ++i)
        array_.push_back(other.array_[i]);
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
    std::vector<int> array_temp(array_);
    std::sort(array_temp.begin(), array_temp.end());
    int short_span = abs(array_temp[0] - array_temp[1]);
    for (int i = 0; i < array_temp.size()- 1 ; ++i)
    {
        short_span = std::min(short_span, abs(array_temp[i] - array_temp[i + 1]));
    }
    return short_span;
}

int Span::longestSpan() const
{
    if (array_.size() < 2)
        throw NotEnoughElement();
    int min = *(std::min_element(array_.begin(), array_.end()));
    int max = *(std::max_element(array_.begin(), array_.end()));

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