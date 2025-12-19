#include "../include/BitcoinExchange.hpp"

void parse_input(BitcoinExchange test, const char* file_name)
{
    std::ifstream file(file_name);
    // if (!file.is_open()) {
    // throw std::runtime_error("Error: could not open file.");
    // }
    std::string line;
    std::getline(file, line);
    // verify_header(line);
    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string item;
        std::getline(ss, item, '|');
        Date date = getDate(item);
        float price = test.search_value(date);
        std::getline(ss, item);
        float number = getNumber(item);
        std::cout << date.to_string() << " => " << number << " = " << number*price << std::endl;
    }
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    BitcoinExchange test("./data.csv");
    Date date("2022-2-11");
    parse_input(test, av[1]);
    // std::cout << test.search_value(date) << std::endl;
    // std::cout << date.to_string() << std::endl;
}