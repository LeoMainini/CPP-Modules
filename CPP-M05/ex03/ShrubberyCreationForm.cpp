#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"
#include "fstream"

using namespace std;

string tree_ascii(
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

ShrubberyCreationForm::ShrubberyCreationForm(string target):
	AForm(target, 145, 137),
	_target(target)
{
	cout << Brown << "Constructor for SCForm called" << NC << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << Red << "Destructor for SCForm called" << NC << endl;
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
			ofstream outStream;
			outStream.open((_target + "_shrubbery").c_str(),
				ostream::trunc | ostream::out);
			if (!outStream.fail())
				outStream << tree_ascii << endl;
			outStream.close();
			cout << executor.getName() << " executed " << getName() << endl;
	}
}