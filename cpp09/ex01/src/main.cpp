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
        stack.push(atoi(line.c_str()));
        std::getline(ss, line, ' ');
        stack.calculate(line[0]);
    }
    std::cout << stack.top() << std::endl;
}

int main(int ac, char **av)
{
    (void)ac;
    RPN stack;
    parse_input(stack, av[1]);
}