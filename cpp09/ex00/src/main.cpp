#include "../include/BitcoinExchange.hpp"

bool is_bisextile(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// bool check_date_for_db
bool is_out_of_month_day(Date date)
{
    int year = date.getYear();
    int month = date.getMonth();
    int day = date.getDay();
    if (month == 2)
    {
        if(is_bisextile(year))
            return year > 29;
        else
            return year > 28;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        return day > 30;
    return false;
}

bool check_possible_date(Date date)
{
    if (date.getYear() < 2009)
        return false;
    if(date.getMonth() < 1 || date.getMonth() > 12)
        return false;
    if(date.getDay() < 1 || date.getDay() > 31)
        return false;
    else
    {
        if(is_out_of_month_day(date))
            return false;
    }
    return true;
}

bool verify_header(std::string line)
{
    return line == "date | value";
}

bool verify_line(const std::string& line)
{
    std::string::size_type sep = line.find(" | ");
    if (sep == std::string::npos) return false;

    std::string date = line.substr(0, sep);
    std::string value = line.substr(sep + 3);

    if (value.empty()) return false;

    // Split date into parts by '-'
    std::istringstream dateStream(date);
    std::string yearStr, monthStr, dayStr;

    if (!std::getline(dateStream, yearStr, '-')) return false;
    if (!std::getline(dateStream, monthStr, '-')) return false;
    if (!std::getline(dateStream, dayStr, '|')) return false;
    if (yearStr.empty() || monthStr.empty() || dayStr.empty()) return false;

    for (int i = 0; i < 4; ++i)
        if (!isdigit(yearStr[i])) return false;
    for (std::string::size_type i = 0; i < monthStr.length(); ++i)
        if (!isdigit(monthStr[i])) return false;
    for (std::string::size_type i = 0; i < dayStr.length(); ++i)
        if (!isdigit(dayStr[i])) return false;

    return true;
}


bool parse_input(BitcoinExchange test, const char* file_name)
{
    std::ifstream file(file_name);
    // if (!file.is_open()) {
    //     throw std::runtime_error("Error: could not open file.");
    // }
    std::string line;
    std::getline(file, line);
    if (!verify_header(line))
        std::cerr << "error: input error in the header => " << line << std::endl;
    while(std::getline(file, line))
    {
        if (!verify_line(line))
        {
            std::cerr << "error: input error in the the line should be Date | value => " << line << std::endl;        
            continue ;
        }
        std::stringstream ss(line);
        std::string item;
        std::getline(ss, item, '|');
        Date date = getDate(item);
        if (check_possible_date(date) == false)
        {
            std::cerr << "error: wrong input => " << item << std::endl;
            continue ;
        }
        float price = test.search_value(date);
        std::getline(ss, item);
        float number = getNumber(item);
        if(number < 0 || number > 1000)
        {
            std::cerr << "error: not a number in the range [0, 1000]" << std::endl;
            continue ;
        }
        std::cout << date.to_string() << " => " << number << " = " << number*price << std::endl;
    }
    return true;
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