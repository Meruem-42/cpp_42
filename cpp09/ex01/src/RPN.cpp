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

int RPN::get_final_result()
{
    if(stack_.size() != 1)
        throw ErrorRPN();
    return (stack_.top());
}

void RPN::calculate(char operation)
{

    if (stack_.size() < 2)
        throw ErrorRPN();
    int num2 = stack_.top();
    if (num2 > 9)
        throw ErrorRPN();
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
            if(num2 == 0)
                throw ErrorRPN();
            result = num1 / num2;
            break;                        
        case '-' :
            result = num1 - num2;
            break;
        default :
            throw ErrorRPN();        
    }
    stack_.push(result);
}

const char *RPN::ErrorRPN::what() const throw()
{
    return ("Error");
}

