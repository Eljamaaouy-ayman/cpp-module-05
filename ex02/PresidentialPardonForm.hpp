#pragma once
#include "AForm.hpp"


class PresidentialPardonForm : public AForm{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        PresidentialPardonForm(std::string target);
        std::string getTarget() const;
        void execute(Bureaucrat const & executer) const;
};