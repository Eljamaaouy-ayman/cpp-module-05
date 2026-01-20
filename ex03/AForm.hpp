#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool sign;
        const int sign_gr;
        const int exec_gr;

    public:
        AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        AForm (std::string name, int sign_grade, int exec_grade);
        class GradeTooLowException: public std::exception
        {
            const char* what() const _GLIBCXX_NOTHROW;
        };
        class GradeTooHighException: public std::exception
        {
            const char* what() const _GLIBCXX_NOTHROW;
        };
        class FormNotSignedException: public std::exception
        {
            const char* what() const _GLIBCXX_NOTHROW;
        };
        std::string getName();
        bool getSign() const;
        int getSign_gr();
        int getExec_gr() const;
        void beSigned(Bureaucrat& other);
        virtual void execute(Bureaucrat const & executer) const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm& other);