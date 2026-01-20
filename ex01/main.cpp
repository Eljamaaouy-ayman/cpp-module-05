#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Ayman" ,1);
		Form b("form_b" , 15, 20);
		Form c("form_c" , 5, 25);
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		b.beSigned(a);
		a.signForm(b);
		for (size_t i = 0; i < 6; i++)
		{
			std::cout << a << std::endl;
			a.decrementGrade();
		}
		c.beSigned(a);
		a.signForm(c);
	}
	catch (std::exception& e)
	{
		std::cout << "throw: " << e.what() << std::endl;
	}
	return 0;
}
