#pragma once
#include "AForm.hpp"
#include <iostream>

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat(std::string const name, int grade);
        class GradeTooLowException: public std::exception
        {
            const char* what() const _GLIBCXX_NOTHROW;
        };
        class GradeTooHighException: public std::exception
        {
            const char* what() const _GLIBCXX_NOTHROW;
        };
        int getGrade() const;
        std::string getName() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm& AForm);
        void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& other);