#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
    T *array_;
    unsigned int size_;

public:
    Array();
    Array(unsigned int size_array);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    unsigned int size() const;
    T &operator[](unsigned int index);

    class OutOfBounds : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("out of bounds");
        }
    };
};

#include "../include/Array.tpp"

#endif