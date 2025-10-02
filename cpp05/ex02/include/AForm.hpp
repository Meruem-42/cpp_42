#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class AForm
{
private:
    const std::string name_;
    bool sign_;
    const int grade_sign_;
    const int grade_exec_;
public:
    AForm(std::string name, int grade_sign, int grade_exec);
    AForm(const AForm& other);
    AForm &operator=(const AForm& other);
    ~AForm();

    class GradeTooHighException : public std::exception
    {
        public :
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public :
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
        public :
        const char *what() const throw();
    };


    std::string getName() const;
    bool getSign() const;
    int getGradeSign() const;
    int getGradeExec() const;

    void beSigned(Bureaucrat& c);
    void execute(Bureaucrat const & executor) const;
    virtual void executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &cout, const AForm& other);


#endif