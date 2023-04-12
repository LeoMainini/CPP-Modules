#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

using namespace std;
//Constructors

AForm::AForm():  _name("default"), _gradeReq(150), _execGradeReq(150), _isSigned(0) {
	cout << Brown << "Default Form constructor called" << NC << endl;
}

AForm::AForm(string name, const unsigned char gradeRed, const unsigned char execGradeReq):
	_name(name), _gradeReq(gradeRed), _execGradeReq(execGradeReq), _isSigned(0) 
{
	if (_gradeReq > 150 || _execGradeReq > 150)
		throw(GradeTooLowException());
	if (_gradeReq < 1 || _execGradeReq < 1)
		throw(GradeTooHighException());
	cout <<  Brown << "Name and Grade constructor called, " << _name << " constructed" << NC << endl;
}

AForm::AForm(const AForm &fCopy):
	_name(fCopy.getName()), _gradeReq(fCopy.getReqGrade()),
	_execGradeReq(fCopy.getExecReqGrade()), _isSigned(fCopy.isSigned())
{
	cout << "Copy constructor called" << endl;
}

AForm::~AForm(){
	cout << "Default form destructor called" << endl;
}

//Operators 
AForm &AForm::operator= (const AForm &fAssign)
{
	if (this != &fAssign)
		_isSigned = fAssign.isSigned();
	return  (*this);
}

ostream &operator<< (std::ostream &out, const AForm &form) {
	out << "form name " << form.getName() << ", grade requires to sign " << form.getReqGrade()
		<< ", to execute " << form.getExecReqGrade();
	form.isSigned() ? out << " and it is signed" : out << "and it isnt signed";
	out << endl;
	return (out);
}

// Getters Setters
bool				AForm::isSigned() const { return _isSigned; }

const std::string	AForm::getName() const { return _name; }

const unsigned char	AForm::getReqGrade() const { return _gradeReq; }

const unsigned char	AForm::getExecReqGrade() const { return _execGradeReq; }

//Functions
const void			AForm::beSigned(const Bureaucrat &signy) {
	if (signy.getGrade() > _gradeReq)
		throw (GradeTooLowException());
	if (_isSigned)
		throw (FormSignedException());
	_isSigned = 1;
}

int				AForm::checkExecReqs(Bureaucrat const & executor) const
{
	if (!isSigned())
		return (1);
	if (executor.getGrade() > getExecReqGrade())
		return (2);
	return (0);
}

//Exceptions

std::string	AForm::GradeTooHighException::text() const throw (){
	return ("grade is too high."); 
}

std::string	AForm::GradeTooLowException::text() const throw (){
	return ("grade is too low."); 
}
std::string	AForm::FormSignedException ::text() const throw (){
	return ("form is already signed or is missing execute signature."); 
}
