#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, const std::size_t array_len, F func)
{
    for (std::size_t i = 0; i < array_len; ++i)
        func(array[i]);
}


template <typename T>
void print_temp(T &x)
{
    std::cout << x << std::endl;
}

template <typename T>
void increment_temp(T& x)
{
    ++x;
}

#endif