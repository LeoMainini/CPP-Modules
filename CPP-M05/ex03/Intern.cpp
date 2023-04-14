#include "Intern.hpp"
#include "colors.h"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using namespace std;

Intern::Intern(){
	cout << Brown << "Intern constructed" << NC << endl;
}

Intern::~Intern(){
	cout << Red << "Intern destructed" << NC << endl;
}

AForm	*Intern::makeRRF(const string &formName) { return (new RobotomyRequestForm(formName)); }

AForm	*Intern::makePPF(const string &formName) { return (new PresidentialPardonForm(formName)); }

AForm	*Intern::makeSCF(const string &formName) { return (new ShrubberyCreationForm(formName)); }

string	*remove_char(const string *str, char c, bool deleteLast)
{
	const string	stro = *str;
	string	*formatedType = new string;
	int	lasti = 0;
	int	i;

	while ((i = stro.find_first_of(c, lasti)) != string::npos)
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

string	*Intern::formatType(const string &formType) const {
	string	*formatedType = remove_char(&formType, ' ', false);
	formatedType = remove_char(formatedType, '	', true);
	for (int i = 0; (*formatedType)[i]; i++)
		if ((*formatedType)[i] >= 'A' && (*formatedType)[i] <= 'Z')
			(*formatedType)[i] += 'a' - 'A';
	return (formatedType);

}

AForm	*Intern::makeForm(const string &formType, const string &formName)
{
	string *formatedType = formatType(formType);
	string	formTypes[] = {"presidentialpardon", "robotomyrequest", "shrubberycreation"};
	int		nTypes = sizeof(formTypes) / sizeof(formTypes[0]);
	AForm	*(Intern::*formFunctions[])(const string &) = {&Intern::makePPF, &Intern::makeRRF, &Intern::makeSCF};
	AForm	*form = 0;

	for (int i = 0; i < nTypes ; i++)
		if (!formatedType->compare(formTypes[i]))
			form = (this->*formFunctions[i])(formName);
	delete (formatedType);
	if (!form)
		cout << LightRed << "Intern failed to create " << formType << NC << endl;
	else
		cout << LightGreen << "Intern created " << formType << " targeted at " << formName << NC << endl;
	return (form);
}

