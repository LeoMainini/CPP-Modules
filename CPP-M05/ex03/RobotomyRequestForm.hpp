#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H
# include "Form.hpp"
# include <iostream>

class RobotomyRequestForm: public AForm {

	private:
		std::string _target;

	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		const void	execute(const Bureaucrat &executor) const;

};

#endif