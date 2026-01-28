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
    Date();
    Date(std::string date);
    Date(const Date& other);
    Date &operator=(const Date& other);
    ~Date();

    bool operator<(const Date& other) const;
    std::string to_string() const;
    int getYear();
    int getMonth();
    int getDay();
};

Date getDate(std::string line);
float getNumber(std::string line);


class BitcoinExchange
{
private:
    std::map<Date, float> mapping_;
public:
    BitcoinExchange();
    BitcoinExchange(const char* file_name);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    
    float search_value(Date key);
};




#endif

