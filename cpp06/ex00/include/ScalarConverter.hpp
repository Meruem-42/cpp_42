#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static void convert(const std::string scalar);
    
};

void convert_from_char(char c);
void convert_from_int(std::string scalar);
void convert_from_float(std::string scalar);
void convert_special_double(std::string scalar);
void convert_special_float(std::string scalar);
void convert_from_float(std::string scalar);
void convert_from_double(std::string scalar);
void convert_from_error(void);

bool is_num(char c);
bool is_digit(const std::string str);
bool is_char(const std::string str);
bool is_int(const std::string str);
bool is_special_float(const std::string str);
bool is_float(const std::string str);
bool is_special_double(const std::string str);
bool is_double(const std::string str);

#endif