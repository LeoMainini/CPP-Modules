#ifndef FORM_H
# define FORM_H

# include <iostream>

class Bureaucrat;

class Form {

	private:
		const std::string	_name;
		const unsigned char	_gradeReq;
		const unsigned char	_execGradeReq;
		bool				_isSigned;
		Form();

	public:
		Form(std::string name, const unsigned char gradeReq);
		Form(const Form &fCopy);
		Form &operator= (const Form &fAssign);
		~Form();
		bool				isSigned() const;
		const std::string	getName() const;
		const unsigned char	getReqGrade() const;
		const unsigned char	getExecReqGrade() const;
		void				beSigned(const Bureaucrat &signy);
		struct	GradeTooHighException: std::exception {
			std::string	text() const throw ();
		};
		struct	GradeTooLowException: std::exception{
			std::string	text() const throw ();
		};
		struct	FormSignedException: std::exception{
			std::string	text() const throw ();
		};

};

std::ostream &operator<< (std::ostream &out, const Form &form);

#endif