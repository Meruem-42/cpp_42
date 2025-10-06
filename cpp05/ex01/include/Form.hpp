#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
private:
    const std::string name_;
    bool sign_;
    const int grade_sign_;
    const int grade_exec_;

public:
    Form(std::string const& n, int gs, int ge);
    Form(const Form& other);
    Form &operator=(const Form& other);
    ~Form();

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

    void beSigned(Bureaucrat& c);
};

std::ostream &operator<<(std::ostream& cout, const Form& other);


#endif