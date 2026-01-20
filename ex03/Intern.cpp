#include "Intern.hpp"

Intern::Intern(){}
Intern::Intern(const Intern& other){*this = other;}
Intern& Intern::operator=(const Intern& other){
    (void)other;
    return *this;
}
Intern::~Intern(){}

AForm* Intern::makeForm(std::string name, std::string target){
    int i = 0;
    std::string arr_form[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

    while(i < 3){
        if(name.compare(arr_form[i]) == 0)
            break;
        i++;
    }

    switch (i)
    {
    case 0:
        return (new ShrubberyCreationForm(target));
    case 1:
        return (new RobotomyRequestForm(target));
    case 2:
        return (new PresidentialPardonForm(target));
    default:
        std::cout << "no form with this name" << std::endl;
        return NULL;
    }
}


