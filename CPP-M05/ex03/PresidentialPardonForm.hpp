#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H
# include "Form.hpp"
# include <iostream>

class PresidentialPardonForm: public AForm {

	private:
		std::string _target;

	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		const void	execute(const Bureaucrat &executor) const;

};

#endif