#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
    T *array_;

public:
    Array();
    Array(unsigned int size_array);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();
};

#endif