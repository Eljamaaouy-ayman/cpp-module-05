#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat a("Ayman" ,15);
		Intern me;
		AForm *b = me.makeForm("ShrubberyCreationForm", "home");
		AForm *c = me.makeForm("RobotomyRequestForm", "school");
		AForm *d = me.makeForm("PresidentialPardonForm", "door");
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
