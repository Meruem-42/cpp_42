#include "../include/RPN.hpp"

void parse_input(RPN stack, std::string input)
{
    std::stringstream ss(input);
    std::string line = "";

    std::getline(ss, line, ' ');
    stack.push(atoi(line.c_str()));
    // std::getline(ss, line, ' ');
    // stack.push(atoi(line.c_str()));
    while (std::getline(ss, line, ' '))
    {
        if (isdigit(line[0]))
            stack.push(atoi(line.c_str()));
        else
            stack.calculate(line[0]);
    }
    std::cout << stack.get_final_result() << std::endl;
}

int main(int ac, char **av)
{
    (void)ac;
    RPN stack;
    try
    {
        parse_input(stack, av[1]);
    }
    catch(RPN::ErrorRPN& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}