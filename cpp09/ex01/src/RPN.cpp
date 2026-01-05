#include "../include/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
    : stack_(other.stack_)
{
}

RPN &RPN::operator=(const RPN& other)
{
    this->stack_ = other.stack_;
    return (*this);
}

RPN::~RPN()
{
}

void RPN::push(int num)
{
    stack_.push(num);
}

int RPN::top()
{
    return (stack_.top());
}


void RPN::calculate(char operation)
{
    int num2 = stack_.top(); 
    stack_.pop();
    int num1 = stack_.top();
    stack_.pop();
    int result;

    switch(operation){
        case '+' :
            result = num1 + num2;
            break;
        case '*' :
            result = num1 * num2;
            break;
        case '/' :
            result = num1 / num2;
            break;                        
        case '-' :
            result = num1 - num2;
            break;
        default :
            return ;        
    }
    stack_.push(result);
}

// void RPN::get_result()
// {

// }
