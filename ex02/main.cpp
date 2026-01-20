#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("Ayman" ,15);
		AForm *b = new ShrubberyCreationForm("school");
		AForm *c = new RobotomyRequestForm("home");
		AForm *d = new PresidentialPardonForm("home");
		std::cout << a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl;
		std::cout << *d << std::endl;
		b->beSigned(a);
		a.signForm(*b);
		a.executeForm(*b);
		c->beSigned(a);
		a.signForm(*c);
		a.executeForm(*c);
		d->beSigned(a);
		a.signForm(*d);
		a.executeForm(*d);
		std::cout << a << std::endl;
		for (size_t i = 0; i < 149; i++)
			a.decrementGrade();
		std::cout << a << std::endl;
		a.executeForm(*c);
		c->beSigned(a);
		a.signForm(*c);
	}
	catch (std::exception& e)
	{
		std::cout << "throw: " << e.what() << std::endl;
	}
	return 0;
}
