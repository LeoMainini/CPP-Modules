#include "RPN.hpp"
#include <sstream>
#include <climits>
#include <algorithm>

std::stack<int>	RPN::_numbers;

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &cp) {}

RPN &RPN::operator=(const RPN &as) { return (*this); }

//returns 10 on error since every number is <10
int	RPN::checkValidNum(std::string &num)
{
	long	numl;

	if (num.find_first_not_of("-0123456789") != std::string::npos)
		return (pError("invalid number '" + num +"'", 10));
	if (num.find("-") != std::string::npos
		&& (num.find_first_of("-") != num.find_last_of("-")
		|| num.find_first_of("0123456789") < num.find("-")))
		return (pError("invalid number '" + num +"'", 10));
	if ((numl = atol(num.c_str())) > 9 || numl < INT_MIN || num.length() > 11)
		return (pError("number out of range '" + num +"'", 10));
	return (atoi(num.c_str()));
}

int		RPN::checkValidToken(std::string &token)
{
	if (token != "+" && token != "-" && token != "/" && token != "*")
		return (token.find_first_of("0123456789") == std::string::npos ? 
			pError("unrecognized token '" + token + "'", 0) : 0);
	if (_numbers.size() < 2)
		return (pError("not enough numbers to execute token", 0));
	return (1);
}

int	RPN::pError(std::string msg, int code)
{
	std::cout << "Error: " << msg << std::endl;
	return (code);
}

void RPN::calculateExpressionResult(std::string &token)
{
	int num = _numbers.top();
	_numbers.pop();
	switch (token.compare("*"))
	{
		case 0:
			num = _numbers.top() * num;
			break ;
		case 1:
			num = _numbers.top() + num;
			break ;
		case 3:
			num = _numbers.top() - num;
			break ;
		case 5:
			num = _numbers.top() / num;
			break ;
	}
	_numbers.pop();
	_numbers.push(num);
}

void	RPN::pResult()
{
	if (_numbers.size() > 1)
		pError("multiple results left in stack", 1);
	while (!_numbers.empty())
	{
		std::cout << _numbers.top() << " ";
		_numbers.pop();
	}
	std::cout << std::endl;
}

void	RPN::calculateExpression(std::string exp)
{
	std::istringstream	exps(exp);
	std::string			token;
	int					num;

	if (exp.find_first_not_of(" 1234567890+-*/") != std::string::npos)
		return ((void)pError("invalid expression => " + exp, 0));
	while (std::getline(exps, token, ' '))
	{
		if (token.empty())
			continue ;
		if (token.find_first_of("0123456789") != std::string::npos
			&& (num = checkValidNum(token)) < 10)
			_numbers.push(num);
		else if (checkValidToken(token))
			calculateExpressionResult(token);
		else
			return ((void)pError("invalid expression => " + exp, 1));
	}
	pResult();
}
