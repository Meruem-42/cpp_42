#include "../include/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)ac;
    BitcoinExchange test(av[1]);
    Date date("2014-11-12");
    std::cout << date.to_string() << std::endl;
}