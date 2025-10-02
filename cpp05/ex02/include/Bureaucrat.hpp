#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
class AForm;

class Bureaucrat
{
private:
    const std::string name_;
    int grade_;
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

    void signForm(AForm& c);

    void executeForm(AForm const & form) const;
};

std::ostream &operator<<(std::ostream &cout, const Bureaucrat &b);

#endif