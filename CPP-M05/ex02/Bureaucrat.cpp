#include "Bureaucrat.hpp"
#include "Form.hpp"
// Constructors
Bureaucrat::Bureaucrat(): _name("default")
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	std::cout << "\e[0;33mString Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned char grade): _name(name)
{
	std::cout << "\e[0;33mString and Grade Constructor called of Bureaucrat\e[0m" << std::endl;
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	_grade = grade;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &bc)
{
	if (this != &bc)
		this->_grade = bc.getGrade();
	return *this;
}

// Getters / Setters
const std::string Bureaucrat::getName() const
{
	return _name;
}
unsigned char Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incGrade()
{
	if (_grade - 1 <= 0)
		throw (GradeTooHighException());
	_grade--;
}

void	Bureaucrat::decGrade()
{
	if (_grade + 1 >= 151)
		throw (GradeTooLowException());
	_grade++;
}

void	Bureaucrat::setGrade(unsigned char grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	_grade = grade;
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << "" << object.getName() << ", bereaucrat grade " << (int)object.getGrade() << ".";
	return stream;
}

//Exception Functions

std::string	Bureaucrat::GradeTooHighException::text() const throw ()
{
	return ("Cannot assign or increment bureaucrat grade to desired value (out of range");
}

std::string	Bureaucrat::GradeTooLowException::text() const throw ()
{
	return ("Cannot assign or decrement bureaucrat grade to desired value (out of range");
}

//Functions

void	Bureaucrat::signForm(AForm &form) const
{

	std::cout << _name;
	try {
		form.beSigned(*this);
		std::cout << " signed " << form.getName();
	}
	catch (AForm::GradeTooLowException &el){
		std::cout << " couldnt sign " << form.getName() << " because " << el.text();
	}
	catch (AForm::FormSignedException &es){
		std::cout << " couldnt sign " << form.getName() << " because " << es.text();
	}
	std::cout << std::endl;
}