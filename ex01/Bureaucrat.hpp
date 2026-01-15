#pragma once

#include <iostream>

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
        int getGrade();
        std::string getName();
        void incrementGrade();
        void decrementGrade();
        void signForm(Form& Form);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& other);