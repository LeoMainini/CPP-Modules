#ifndef RPN_H
#define RPN_H
#include <iostream>
#include <stack>


class RPN {
	private:
		static std::stack<int>	_numbers;
		static int	checkValidNum(std::string &num);
		static int	checkValidToken(std::string &token);
		static int	pError(std::string msg, int code);
		static void	calculateExpressionResult(std::string &token);
		RPN();
		RPN(const RPN &cp);
		RPN &operator=(const RPN &as);
		~RPN();

	public:
		static void	calculateExpression(std::string exp);
};

#endif