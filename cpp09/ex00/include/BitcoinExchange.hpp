#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class Date
{
private :
    int year_;
    int month_;
    int day_;
public :
    Date(std::string date);
    bool operator<(const Date& other) const;
    std::string to_string() const;
    int getYear();
    int getMonth();
    int getDay();
};

std::ostream &operator<<(std::ostream &stream, const Date &date);
Date getDate(std::string line);
float getNumber(std::string line);


class BitcoinExchange
{
private:
    std::map<Date, float> mapping_;
public:
    // BitcoinExchange();
    BitcoinExchange(const char* file_name);
    // ~BitcoinExchange();
    float search_value(Date key);
};




#endif

