#ifndef	INTERN_H
# define INTERN_H
# include <iostream>

class AForm;

class Intern
{
private:
	/* data */
public:
	Intern();
	~Intern();
	AForm	*makeForm(std::string formType, std::string formName);
	

};

#endif