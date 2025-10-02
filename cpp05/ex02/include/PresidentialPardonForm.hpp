#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "../include/AForm.hpp"
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private :
    std::string target_; 
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    void executeAction() const override;
};

#endif