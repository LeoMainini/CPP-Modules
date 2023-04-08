#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try {
			Bureaucrat bc("Thommas the fiat 500 alpha", 250);
		}
		catch (std::exception &e) {
			std::cout << "Error" << std::endl;
		}
		try {
			Bureaucrat bc("Thommas the fiat 500 beta", 1);
		}
		catch (std::exception &e) {
			std::cout << "Error" << std::endl;
		}
	}
	{
		Bureaucrat bc("Thommas the fiat 500");
		
		try{
			bc.setGrade(2);
			std::cout << bc << std::endl;
			bc.incGrade();
			std::cout << bc << std::endl;
			bc.incGrade();
		}
		catch (std::exception &e){
			std::cout << "Error " << std::endl;
		}
	}
	{
		Bureaucrat bc("Thommas the fiat 502 electric bogaloo");
		
		try{
			bc.setGrade(149);
			std::cout << bc << std::endl;
			bc.decGrade();
			std::cout << bc << std::endl;
			bc.decGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e){
			std::cout << "Error: " << e.text() << std::endl;
		}
	}
}