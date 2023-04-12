#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "colors.h"

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

const void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	switch (checkExecReqs(executor)){
		case 1:
			throw (AForm::FormSignedException());
			break ;
		case 2:
			throw (AForm::GradeTooLowException());
			break ;
		default:
			cout << LightGreen << tree_ascii << NC << endl;

	}
	//cout << LightGreen << tree_ascii << NC << endl;
}