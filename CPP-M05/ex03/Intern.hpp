#ifndef	INTERN_H
# define INTERN_H
# include <iostream>

class	AForm;
class	RobotomyRequestForm;
class	PresidentialPardonForm;
class	ShrubberyCreationForm;

class Intern
{

private:
	AForm		*makeRRF(const std::string &formName);
	AForm		*makePPF(const std::string &formName);
	AForm		*makeSCF(const std::string &formName);
	std::string	*formatType(const std::string &formType) const;


public:
	Intern();
	~Intern();
	AForm	*makeForm(const std::string &formType, const std::string &formName);
	

};

#endif