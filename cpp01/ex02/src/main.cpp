#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Adress of the string variable is : " << &str << std::endl;
    std::cout << "Adress of the pointer to the string is : " << stringPTR << std::endl;
    std::cout << "Adress of the reference to the string is : " << &stringREF << std::endl;

    std::cout << "Value of the string variable is : " << str << std::endl;
    std::cout << "Value pointed to by the pointer is : " << *stringPTR << std::endl;
    std::cout << "Adress pointed to by the reference is : " << stringREF << std::endl;
}
