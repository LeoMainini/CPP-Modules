#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"



PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm(target, 25, 5),
	_target(target)
{
	std::cout << Brown << "Constructor for PPForm called" << NC << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << Red << "Destructor for PPForm called" << NC << std::endl;
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
			std::cout << LightGreen << _target << " has been pardoned by Zaphod Beeblebrox."
				<<  NC << std::endl;
	}
}