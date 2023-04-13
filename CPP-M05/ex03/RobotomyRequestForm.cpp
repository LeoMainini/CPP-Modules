#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

using namespace std;

RobotomyRequestForm::RobotomyRequestForm(string target):
	AForm(target, 72, 45),
	_target(target)
{
	cout << Brown << "Constructor for RRForm called" << NC << endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	cout << Red << "Destructor for RRForm called" << NC << endl;
}

const void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	switch (checkExecReqs(executor)){
		case 1:
			cout << LightRed << "Robotomy failed" << NC << endl;
			throw (AForm::FormSignedException());
			break ;
		case 2:
			cout << LightRed << "Robotomy failed" << NC << endl;
			throw (AForm::GradeTooLowException());
			break ;
		default:
			cout << Yellow << "\"BRRRRRRRZZZZRRRRRR\": " << Purple << _target
				<< " has been robotomized successfully 50% of the time" << NC << endl;
			
	}
}