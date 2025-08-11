#include <iostream>

class Megaphone
{
private:
    std::string message;

public:
    Megaphone(const std::string &str)
        : message(str) {}
    void ft_shout()
    {
        for (size_t i = 0; i < message.length(); ++i)
            std::cout << (char)std::toupper(message[i]);
    }
};

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    int i = 1;

    while (av[i])
    {
        Megaphone m(av[i++]);
        m.ft_shout();
    }
    std::cout << std::endl;
}