#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("ayman", 1);
        std::cout<< a;

        a.incrementGrade();
        std::cout<< a;
    }
    catch(const std::exception& e)
    {
        std::cerr << "thrown " << e.what() << '\n';
    }
    


}