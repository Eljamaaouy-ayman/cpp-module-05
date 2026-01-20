#pragma once
#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(std::string target);
        std::string getTarget() const;
        void execute(Bureaucrat const & executer) const;
};