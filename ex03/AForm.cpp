#include "AForm.hpp"

AForm::AForm():name("unknown"), sign_gr(150), exec_gr(150){
    sign = false;
}

AForm::AForm(const AForm& other):name(other.name), sign_gr(other.sign_gr), exec_gr(other.exec_gr){
    sign = other.sign;
}
AForm& AForm::operator=(const AForm& other){
    (void)other;
    return *this;
}

AForm::~AForm(){}

AForm::AForm(std::string name, int sign_grade, int exec_grade):name(name), sign_gr(sign_grade), exec_gr(exec_grade){
    sign = false;
    if(sign_gr > 150 || exec_gr > 150)
        throw AForm::GradeTooLowException();
    else if(sign_gr < 1 || exec_gr < 1)
        throw AForm::GradeTooHighException();
}

const char* AForm::GradeTooLowException::what() const _GLIBCXX_NOTHROW{
    return "grade too low";
}

const char* AForm::GradeTooHighException::what() const _GLIBCXX_NOTHROW{
    return "grade too high";
}

const char* AForm::FormNotSignedException::what() const _GLIBCXX_NOTHROW{
    return "form not signed";
}

std::string AForm::getName(){
    return name;
}

bool AForm::getSign() const{
    return sign;
}

int AForm::getSign_gr(){
    return sign_gr;
}

int AForm::getExec_gr() const{
    return exec_gr;
}

void AForm::beSigned(Bureaucrat& other){
    if (sign_gr >= other.getGrade())
        sign = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, AForm& other){
    os << "form " << other.getName() << " sign " << other.getSign() << " grade sign " << other.getSign_gr() << " execute grade " << other.getExec_gr();
    return os;
}