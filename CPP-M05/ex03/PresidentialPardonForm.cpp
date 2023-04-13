#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

using namespace std;

PresidentialPardonForm::PresidentialPardonForm(string target):
	AForm(target, 25, 5),
	_target(target)
{
	cout << Brown << "Constructor for PPForm called" << NC << endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	cout << Red << "Destructor for PPForm called" << NC << endl;
}

const void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	switch (checkExecReqs(executor)){
		case 1:
			throw (AForm::FormSignedException());
			break ;
		case 2:
			throw (AForm::GradeTooLowException());
			break ;
		default:
			cout << LightGreen << _target << " has been pardoned by Zaphod Beeblebrox."
				<<  NC << endl;
	}
}