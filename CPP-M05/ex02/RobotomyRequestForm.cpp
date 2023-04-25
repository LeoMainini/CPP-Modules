#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"



RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm(target, 72, 45),
	_target(target)
{
	std::cout << Brown << "Constructor for RRForm called" << NC << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << Red << "Destructor for RRForm called" << NC << std::endl;
}

const void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	switch (checkExecReqs(executor)){
		case 1:
			std::cout << LightRed << "Robotomy failed" << NC << std::endl;
			throw (AForm::FormSignedException());
			break ;
		case 2:
			std::cout << LightRed << "Robotomy failed" << NC << std::endl;
			throw (AForm::GradeTooLowException());
			break ;
		default:
			std::cout << Yellow << "\"BRRRRRRRZZZZRRRRRR\": " << Purple << _target
				<< " has been robotomized successfully 50% of the time" << NC << std::endl;
			
	}
}