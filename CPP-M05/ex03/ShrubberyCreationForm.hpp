#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H
# include "Form.hpp"
# include <iostream>

class ShrubberyCreationForm: public AForm {

	private:
		std::string _target;

	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		const void	execute(const Bureaucrat &executor) const;

};

#endif
