#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat(std::string n, int g);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

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
    int getGrade() const;
    
    void incrementGrade();
    void decrementGrade();

    void signForm(Form& c);
};

std::ostream &operator<<(std::ostream &cout, const Bureaucrat &b);



#endif