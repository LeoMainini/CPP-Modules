/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:16:11 by leferrei          #+#    #+#             */
/*   Updated: 2023/04/25 19:40:22 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"


//Constructors

Form::Form():  _name("default"), _gradeReq(150), _execGradeReq(150), _isSigned(0) {
	std::cout << Brown << "Default Form constructor called" << NC << std::endl;
}

Form::Form(std::string name, unsigned char gradeRed):
	_name(name), _gradeReq(gradeRed), _execGradeReq(0), _isSigned(0) 
{
	if (_gradeReq > 150)
		throw(GradeTooLowException());
	if (_gradeReq < 1)
		throw(GradeTooHighException());
	std::cout <<  Brown << "Name and Grade constructor called, " << _name << " constructed" << NC << std::endl;
}

Form::Form(const Form &fCopy):
	_name(fCopy.getName()), _gradeReq(fCopy.getReqGrade()),
	_execGradeReq(fCopy.getExecReqGrade()), _isSigned(fCopy.isSigned())
{
	std::cout << "Copy constructor called" << std::endl;
}

Form::~Form(){
	std::cout << "Default form destructor called" << std::endl;
}

//Operators 
Form &Form::operator= (const Form &fAssign)
{
	if (this != &fAssign)
		_isSigned = fAssign.isSigned();
	return  (*this);
}

std::ostream &operator<< (std::ostream &out, const Form &form) {
	out << "form name " << form.getName() << ", grade requires to sign " << form.getReqGrade()
		<< ", to execute " << form.getExecReqGrade();
	form.isSigned() ? out << " and it is signed" : out << "and it isnt signed";
	out << std::endl;
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
