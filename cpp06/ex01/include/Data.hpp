#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
private:
    int data_;
public:
    Data();
    Data(int data);
    Data(const Data& other);
    Data &operator=(const Data& other);

    int get_data();
    ~Data();
};

#endif