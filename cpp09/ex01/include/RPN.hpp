#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib> 

class RPN
{
private :
    std::stack<int> stack_;

public :
    RPN();
    RPN(const RPN& other);
    RPN &operator=(const RPN& other);
    ~RPN();

    void push(int num);
    int top();
    void calculate(char operation);
    // void get_result();
};

#endif