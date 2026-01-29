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
    int get_final_result();
    void calculate(char operation);
    
    class ErrorRPN : public std::exception
    {
    public :
        const char *what() const throw();
    };
};

#endif