#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Unkown"){
    grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name){
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if(grade < 0)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what()const _GLIBCXX_NOTHROW{
    return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what()const _GLIBCXX_NOTHROW{
    return "grade too low";
}

int Bureaucrat::getGrade(){
    return grade;
}

std::string Bureaucrat::getName (){
    return name;
}

void Bureaucrat::incrementGrade(){
    if(grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        grade--;
}

void Bureaucrat::decrementGrade(){
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade++;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& other){
    os << other.getName() << " , bureaucrat grade " << other.getGrade() << std::endl;
    return os;
}