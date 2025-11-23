#include "../include/BitcoinExchange.hpp"


int toInt(std::string str)
{
    std::stringstream ss;
    int temp;
    ss << str;
    ss >> temp;
    return temp;
}

Date::Date(std::string date)
{
    size_t pos;
    size_t start = 0;
    // if(pos = date.find("-", start) != std::string::npos)
    //     exception 
    pos = date.find("-", start);
    year_ =  toInt(date.substr(start, pos - start));
    start = pos + 1;

    pos = date.find("-", start);
    month_ =  toInt(date.substr(start, pos - start));
    start = pos + 1;

    pos = date.find("-", start);
    day_ =  toInt(date.substr(start, pos - start));
}


bool Date::operator<(const Date& other) const
{
    if(this->year_ < other.year_)
        return true;
    if(this->month_ < other.month_)
        return true;
    if(this->day_ < other.day_)
        return true;
    return false;
}

std::string Date::to_string() const
{
    std::stringstream ss;
    ss << year_ << "-" << month_ << "-" << day_;
    return ss.str();
}



// void check_and_map_line(std::string line)
// {
//     // mapping_[get_date_key(line)];
// }

BitcoinExchange::BitcoinExchange(const char* file_name)
{
    std::ifstream file(file_name);
    // if (!file.is_open()) {
    // throw std::runtime_error("Error: could not open file.");
    // }
    std::string line;
    std::getline(file, line);
    // verify_header(line);
    while(std::getline(file, line))
        // check_and_map_line(line);
        std::cout << line << "\n";

}
