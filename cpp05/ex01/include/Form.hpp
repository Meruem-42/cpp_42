#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool sign;
    const int grade_sign;
    const int grade_exec;

public:
    Form(std::string& n, int gs, int ge);
    Form(const Form& other);
    Form &operator=(const Form& other);

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    std::string getName() const;
    bool getSign() const;
    int getGradeSign() const;
    int getGradeExec() const;

    ~Form();
    void beSigned(Bureaucrat& c);

};

std::ostream &operator<<(std::ostream& cout, const Form& other);


#endif