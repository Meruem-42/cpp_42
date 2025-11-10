#include "../include/Span.hpp"

Span::Span()
    : array_(NULL), N_(0), fill_number_(0)
{
}

Span::Span(unsigned int N)
    : N_(N), fill_number_(0)
{
    array_ = new int[N_];
}

Span::Span(const Span &other)
    : N_(other.N_), fill_number_(other.fill_number_)
{
    array_ = new int[N_];
    for (unsigned int i = 0; i < N_; ++i)
        array_[i] = other.array_[i];
}

Span &Span::operator=(const Span &other)
{
    this->N_ = other.N_;
    this->fill_number_ = other.fill_number_;
    delete this->array_;
    this->array_ = new int[N_];
    for (unsigned int i = 0; i < N_; ++i)
        this->array_[i] = other.array_[i];
    return (*this);
}

Span::~Span()
{
    delete array_;
}

void Span::addNumber(int num)
{
    if(fill_number_ == N_)
        throw IsFull();
    array_[fill_number_] = num;
    ++fill_number_;
}

int Span::shortestSpan() const
{
    if(fill_number_ < 2)
        throw NotEnoughElement();
    int short_span = 0;
    for(unsigned int i = 0; i < N_; ++i)
        for(unsigned int j = i + 1; j < N_; ++j)
        {
            if(i == 0)
                short_span = abs(array_[i] - array_[j]);
            if (abs(array_[i] - array_[j]) < short_span)
                short_span = abs(array_[i] - array_[j]);
        }
    return short_span;
}

int Span::longestSpan() const
{

    if(fill_number_ < 2)
        throw NotEnoughElement();
    int max;
    int min;
    for(unsigned int i = 0; i < N_; ++i) {
        if(i == 0)
            max = array_[i];
        if(array_[i] > max)
            max = array_[i];
    }
    for(unsigned int i = 0; i < N_; ++i) {
        if(i == 0)
            min = array_[i];
        if(array_[i] < min)
            min = array_[i];
    }

    return max - min;
}


const char *Span::IsFull::why() const throw()
{
    return ("Span is full");
}

const char *Span::NotEnoughElement::why() const throw()
{
    return ("array need to have more than 1 element");
}


