#include "../include/BitcoinExchange.hpp"


int toInt(std::string str)
{
    std::stringstream ss(str);
    int temp;
    ss >> temp;
    return temp;
}

float toFloat(std::string str)
{
    std::stringstream ss(str);
    float temp;
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

Date::Date()
{
    year_ = 0;
    month_ = 0;
    day_ = 0;
}

Date::Date(const Date& other)
    : year_(other.year_), month_(other.month_), day_(other.day_)
{
}

Date &Date::operator=(const Date& other)
{
    this->year_ = other.year_;
    this->month_ = other.month_;
    this->day_ = other.day_;
    return (*this);
}

Date::~Date()
{
}



bool Date::operator<(const Date& other) const
{
    if (year_ != other.year_)
        return year_ < other.year_;
    if (month_ != other.month_)
        return month_ < other.month_;
    return day_ < other.day_;
}



std::string Date::to_string() const
{
    std::stringstream ss;
    ss << year_ << "-";
    if (month_ < 10)
        ss << "0"; 
    ss << month_ << "-";
    if (day_ < 10)
        ss << "0"; 
    ss << day_;
    return ss.str();
}

int Date::getYear()
{
    return (year_);
}

int Date::getMonth()
{
    return (month_);
}

int Date::getDay()
{
    return (day_);
}


Date getDate(std::string line)
{
    return Date(line);
}

float getNumber(std::string line)
{
    return (toFloat(line));
}

BitcoinExchange::BitcoinExchange()
{
}

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
    {
        std::stringstream ss(line);
        std::string item;
        std::getline(ss, item, ',');
        Date date = getDate(item);
        // std::cout << date.to_string();
        std::getline(ss, item);
        float number = getNumber(item);
        // std::cout << " | " << number << std::endl;
        mapping_[date] = number;

    }
    // for (std::map<Date, float>::const_iterator it = mapping_.begin();
    //     it != mapping_.end();
    //     ++it)
    // {
    //     const Date& key = it->first;
    //     float value = it->second;

    //     std::cout << key.to_string() << " -> " << value << '\n';
    // }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->mapping_.insert(other.mapping_.begin(), other.mapping_.end());
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    mapping_.insert(other.mapping_.begin(), other.mapping_.end());
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}


float BitcoinExchange::search_value(Date key)
{
    std::map<Date, float>::const_iterator it = mapping_.lower_bound(key);
    if(it != mapping_.begin() && key < it->first)
        --it;
    if (it == mapping_.end())
        --it;
    return (it->second);
}
