#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool sign;
        const int sign_gr;
        const int exec_gr;

    public:
        Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        Form (std::string name, int sign_grade, int exec_grade);
        class GradeTooLowException: public std::exception
        {
            const char* what() const _GLIBCXX_NOTHROW;
        };
        class GradeTooHighException: public std::exception
        {
            const char* what() const _GLIBCXX_NOTHROW;
        };
        std::string getName();
        bool getSign();
        int getSign_gr();
        int getExec_gr();
        void beSigned(Bureaucrat& other);
};

std::ostream& operator<<(std::ostream& os, Form& other);