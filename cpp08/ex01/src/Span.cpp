#include "../include/Span.hpp"

Span::Span()
    : array_(nullptr), N_(0), fill_number_(0)
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

const char *Span::IsFull::why() const
{
    return ("Span is full");
}
