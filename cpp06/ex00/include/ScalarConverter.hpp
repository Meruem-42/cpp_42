#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

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

#endif