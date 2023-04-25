#include "Intern.hpp"
#include "colors.h"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"



Intern::Intern(){
	std::cout << Brown << "Intern constructed" << NC << std::endl;
}

Intern::~Intern(){
	std::cout << Red << "Intern destructed" << NC << std::endl;
}

AForm	*Intern::makeRRF(const std::string &formName) { return (new RobotomyRequestForm(formName)); }

AForm	*Intern::makePPF(const std::string &formName) { return (new PresidentialPardonForm(formName)); }

AForm	*Intern::makeSCF(const std::string &formName) { return (new ShrubberyCreationForm(formName)); }

string	*remove_char(const std::string *str, char c, bool deleteLast)
{
	const std::string	stro = *str;
	std::string	*formatedType = new std::string;
	int	lasti = 0;
	int	i;

	while ((i = stro.find_first_of(c, lasti)) != std::string::npos)
	{
		formatedType->append(stro.substr(lasti, i - lasti));
		lasti = i + 1;
	}
	if (stro[lasti])
		formatedType->append(stro.substr(lasti, stro.length() - lasti + 1));
	if (deleteLast)
		delete (str);
	return (formatedType);
}

string	*Intern::formatType(const std::string &formType) const {
	std::string	*formatedType = remove_char(&formType, ' ', false);
	formatedType = remove_char(formatedType, '	', true);
	for (int i = 0; (*formatedType)[i]; i++)
		if ((*formatedType)[i] >= 'A' && (*formatedType)[i] <= 'Z')
			(*formatedType)[i] += 'a' - 'A';
	return (formatedType);

}

AForm	*Intern::makeForm(const std::string &formType, const std::string &formName)
{
	std::string *formatedType = formatType(formType);
	std::string	formTypes[] = {"presidentialpardon", "robotomyrequest", "shrubberycreation"};
	int		nTypes = sizeof(formTypes) / sizeof(formTypes[0]);
	AForm	*(Intern::*formFunctions[])(const std::string &) = {&Intern::makePPF, &Intern::makeRRF, &Intern::makeSCF};
	AForm	*form = 0;

	for (int i = 0; i < nTypes ; i++)
		if (!formatedType->compare(formTypes[i]))
			form = (this->*formFunctions[i])(formName);
	delete (formatedType);
	if (!form)
		std::cout << LightRed << "Intern failed to create " << formType << NC << std::endl;
	else
		std::cout << LightGreen << "Intern created " << formType << " targeted at " << formName << NC << std::endl;
	return (form);
}

