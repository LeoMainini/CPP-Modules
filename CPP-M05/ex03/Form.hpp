#ifndef A_FORM_H
# define A_FORM_H

# include <iostream>

class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		const unsigned char	_gradeReq;
		const unsigned char	_execGradeReq;
		bool				_isSigned;
		AForm();

	public:
		AForm(std::string name, const unsigned char gradeReq, const unsigned char execGradeReq);
		AForm(const AForm &fCopy);
		AForm &operator= (const AForm &fAssign);
		virtual ~AForm();
		bool				isSigned() const;
		const std::string	getName() const;
		const unsigned char	getReqGrade() const;
		const unsigned char	getExecReqGrade() const;
		const void			beSigned(const Bureaucrat &signy);
		int					checkExecReqs(Bureaucrat const & executor) const;
		virtual const void	execute(Bureaucrat const &executor) const = 0;
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

std::ostream &operator<< (std::ostream &out, const AForm &form);

#endif