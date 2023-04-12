#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

using namespace std;
//Constructors

Form::Form():  _name("default"), _gradeReq(150), _execGradeReq(150), _isSigned(0) {
	cout << Brown << "Default Form constructor called" << NC << endl;
}

Form::Form(string name, unsigned char gradeRed):
	_name(name), _gradeReq(gradeRed), _execGradeReq(0), _isSigned(0) 
{
	if (_gradeReq > 150)
		throw(GradeTooLowException());
	if (_gradeReq < 1)
		throw(GradeTooHighException());
	cout <<  Brown << "Name and Grade constructor called, " << _name << " constructed" << NC << endl;
}

Form::Form(const Form &fCopy):
	_name(fCopy.getName()), _gradeReq(fCopy.getReqGrade()),
	_execGradeReq(fCopy.getExecReqGrade()), _isSigned(fCopy.isSigned())
{
	cout << "Copy constructor called" << endl;
}

Form::~Form(){
	cout << "Default form destructor called" << endl;
}

//Operators 
Form &Form::operator= (const Form &fAssign)
{
	if (this != &fAssign)
		_isSigned = fAssign.isSigned();
	return  (*this);
}

ostream &operator<< (std::ostream &out, const Form &form) {
	out << "form name " << form.getName() << ", grade requires to sign " << form.getReqGrade()
		<< ", to execute " << form.getExecReqGrade();
	form.isSigned() ? out << " and it is signed" : out << "and it isnt signed";
	out << endl;
	return (out);
}

// Getters Setters
bool				Form::isSigned() const { return _isSigned; }

const std::string	Form::getName() const { return _name; }

const unsigned char	Form::getReqGrade() const { return _gradeReq; }

const unsigned char	Form::getExecReqGrade() const { return _execGradeReq; }

//Functions
const void			Form::beSigned(const Bureaucrat &signy) {
	if (signy.getGrade() > _gradeReq)
		throw (GradeTooLowException());
	if (_isSigned)
		throw (FormSignedException());
	_isSigned = 1;
}

//Exceptions

std::string	Form::GradeTooHighException::text() const throw (){
	return ("grade is too high."); 
}

std::string	Form::GradeTooLowException::text() const throw (){
	return ("grade is too low."); 
}
std::string	Form::FormSignedException ::text() const throw (){
	return ("form is already signed."); 
}
