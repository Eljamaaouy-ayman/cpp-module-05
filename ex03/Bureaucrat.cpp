#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

int Bureaucrat::getGrade() const{
    return grade;
}

std::string Bureaucrat::getName () const{
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
    os << other.getName() << " , bureaucrat grade " << other.getGrade();
    return os;
}

void Bureaucrat::signForm(AForm& AForm){
    if (AForm.getSign() == true)
        std::cout << getName() << " signed " << AForm.getName() << std::endl;
    else
        std::cout << getName() << " couldn't sign " << AForm.getName() << "because the bureaucrat has a low grade!!" << std::endl; 
}

void Bureaucrat::executeForm(AForm const & form) const
{
    form.execute(*this);
}
