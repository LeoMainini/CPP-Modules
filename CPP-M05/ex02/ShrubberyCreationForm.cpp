#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"
#include "fstream"



std::string tree_ascii(
"              v .   ._, |_  .,\n"\
"           `-._\\/  .  \\ /    |/_\n"\
"               \\  _\\, y | \\//\n"\
"         _\\_.___\\, \\/ -.\\||\n"\
"           `7-,--.`._||  / / ,\n"\
"           /'     `-. `./ / |/_.'\n"\
"                     |    |//\n"\
"                     |_    /\n"\
"                     |-   |\n"\
"                     |   =|\n"\
"                     |    |\n"\
"--------------------/ ,  . \\--------._"
);

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm(target, 145, 137),
	_target(target)
{
	std::cout << Brown << "Constructor for SCForm called" << NC << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << Red << "Destructor for SCForm called" << NC << std::endl;
}

const void ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
	switch (checkExecReqs(executor)){
		case 1:
			throw (AForm::FormSignedException());
			break ;
		case 2:
			throw (AForm::GradeTooLowException());
			break ;
		default:
			std::ofstream outStream;
			outStream.open((_target + "_shrubbery").c_str(),
				std::ostream::trunc | std::ostream::out);
			if (!outStream.fail())
				outStream << tree_ascii << std::endl;
			outStream.close();
			std::cout << executor.getName() << " executed " << getName() << std::endl;
	}
}