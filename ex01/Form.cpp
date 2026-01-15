#include "Form.hpp"

Form::Form():name("unknown"), sign_gr(150), exec_gr(150){
    sign = false;
}

Form::Form(const Form& other):name(other.name), sign_gr(other.sign_gr), exec_gr(other.exec_gr){
    sign = other.sign;
}
Form& Form::operator=(const Form& other){
    (void)other;
    return *this;
}

Form::~Form(){}

Form::Form(std::string name, int sign_grade, int exec_grade):sign_gr(sign_grade), exec_gr(exec_grade){
    name = name;
    sign = false;
    if(sign_gr > 150 || exec_gr > 150)
        throw Form::GradeTooLowException();
    else if(sign_gr < 1 || exec_gr < 1)
        throw Form::GradeTooHighException();
}

const char* Form::GradeTooLowException::what() const _GLIBCXX_NOTHROW{
    return "grade too low";
}

const char* Form::GradeTooHighException::what() const _GLIBCXX_NOTHROW{
    return "grade too high";
}

std::string Form::getName(){
    return name;
}

bool Form::getSign(){
    return sign;
}

int Form::getSign_gr(){
    return sign_gr;
}

int Form::getExec_gr(){
    return exec_gr;
}

void Form::beSigned(Bureaucrat& other){
    if (sign_gr >= other.getGrade())
        sign = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Form& other){
    os << "form" << other.getName() << "sign" << other.getSign() << "grade sign" << other.getSign_gr() << "execute grade" << other.getExec_gr() << std::endl;
}