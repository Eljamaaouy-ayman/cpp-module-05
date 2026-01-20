#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("unknown"){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other){
    target = other.target;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    target = other.target;
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("ShrubberyForm", 25, 5), target(target){}

std::string PresidentialPardonForm::getTarget() const {
    return target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executer) const
{
    if(executer.getGrade() > getExec_gr())
        throw AForm::GradeTooLowException();
    else if (getSign() == false)
        throw AForm::FormNotSignedException();
    else
        std::cout << "the " << getTarget() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}
