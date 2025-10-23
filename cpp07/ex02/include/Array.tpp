// #include "../include/Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array()
    : array_(NULL), size_(0)
{
}

template <typename T>
Array<T>::Array(unsigned int size_array)
    : array_(new T[size_array]()), size_(size_array)
{
}

template <typename T>
Array<T>::Array(const Array &other)
    : size_(other.size_)
{
    unsigned int size = other.size();
    array_ = new T[size]();
    for (unsigned int i = 0; i < size; ++i)
        array_[i] = other.array_[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    unsigned int size = other.size();
    delete[] array_;
    size_ = size;
    array_ = new T[size]();
    for (unsigned int i = 0; i < size; ++i)
        array_[i] = other.array_[i];
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Default dest" << std::endl;
    delete[] array_;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (size_);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index > size_ - 1)
        throw Array<T>::OutOfBounds();
    return (array_[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index > size_ - 1)
        throw OutOfBounds::what();
    return (array_[index]);
}
