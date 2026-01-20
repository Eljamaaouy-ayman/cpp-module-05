#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("unknown"){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other){
    target = other.target;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    target = other.target;
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("ShrubberyForm", 72, 45), target(target){}

std::string RobotomyRequestForm::getTarget() const {
    return target;
}

static int i = 0;

void RobotomyRequestForm::execute(Bureaucrat const & executer) const{
    if (executer.getGrade() > getExec_gr())
        throw AForm::GradeTooLowException();
    else if (getSign() == false)
        throw AForm::FormNotSignedException();
    if (i % 2 == 0)
        std::cout << "the " << getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "the robotomy failed" << std::endl;
    i++;
}
