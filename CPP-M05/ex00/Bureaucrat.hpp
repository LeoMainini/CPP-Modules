#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat//: public std::exception
{
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, unsigned char grade);
		
		// Destructor
		~Bureaucrat();
		
		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);
		
		// Getters / Setters
		const std::string	getName() const;
		unsigned char		getGrade() const;
		void				incGrade();
		void				decGrade();	
		void				setGrade(unsigned char grade);
		struct				GradeTooHighException: public std::exception{
			std::string		text() const throw ();
		};
		struct				GradeTooLowException: public std::exception{
			std::string		text() const throw ();
		};

	private:
		const std::string _name;
		unsigned char _grade;
		
};

std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object);

#endif