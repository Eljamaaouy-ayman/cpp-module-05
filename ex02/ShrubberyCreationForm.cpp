#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyRequestForm", 145, 137), target("unknown"){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other){
    target = other.target;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    target = other.target;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyForm", 145, 137), target(target){}

std::string ShrubberyCreationForm::getTarget() const {
    return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executer) const{
    if (executer.getGrade() > getExec_gr())
		throw AForm::GradeTooLowException();
    else if (getSign() == false)
        throw AForm::FormNotSignedException();
    else{
        std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
        outfile <<
		"         v" << std::endl <<
		"        >X<" << std::endl <<
		"         A" << std::endl <<
		"        d$b" << std::endl <<
		"      .d\\$$b." << std::endl <<
		"    .d$i$$\\$$b." << std::endl <<
		"       d$$@b" << std::endl <<
		"      d\\$$$ib" << std::endl <<
		"    .d$$$\\$$$b" << std::endl <<
		"  .d$$@$$$$\\$$ib." << std::endl <<
		"      d$$i$$b" << std::endl <<
		"     d\\$$$$@$b" << std::endl <<
		"  .d$@$$\\$$$$$@b." << std::endl <<
		".d$$$$i$$$\\$$$$$$b." << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl;
        outfile.close();
        std::cout << executer.getName() << " executed shruberryCreationForm" << std::endl;
    }    
}



