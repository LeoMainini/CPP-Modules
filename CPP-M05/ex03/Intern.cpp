#include "Intern.hpp"
#include "colors.h"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using namespace std;

Intern::Intern(){
	cout << Brown << "Intern constructed" << NC << endl;
}

Intern::~Intern(){
	cout << Red << "Intern destructed" << NC << endl;
}

AForm	*Intern::makeForm(string formType, string formName){
	enum string  {presidentialpardon, robotomyrequest, shrubberycreation};
	
	AForm *ret = new PresidentialPardonForm(formName); 

	return (ret);
}

