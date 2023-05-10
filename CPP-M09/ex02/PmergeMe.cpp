#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>

//Must init after calling constructor
PmergeMe::PmergeMe(): _isInit(false) { }

PmergeMe::PmergeMe(char **numberList): _isInit(false) 
{
	if (!numberList && pError("Invalid string array pointer passed to constructor", 0))
		return ;
	_isInit = init(numberList);
}

PmergeMe::PmergeMe(const PmergeMe &cp)
{
	*this = cp;
}

PmergeMe &PmergeMe::operator= (const PmergeMe &as)
{
	if (&as != this && as._isInit)
	{
		_numList.resize(as._numList.size());
		_numVector.resize(as._numVector.size());
		std::copy(as._numList.begin(), as._numList.end(), _numList.begin());
		std::copy(as._numVector.begin(), as._numVector.end(), _numVector.begin());
		_isInit = as._isInit;
	}
	else if (&as != this && _isInit)
	{
		_numList.erase(_numList.begin(), _numList.end());
		_numVector.erase(_numVector.begin(), _numVector.end());
		_numList.resize(0);
		_numVector.resize(0);
		_isInit = false;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){ }

int	PmergeMe::init(char **numberList)
{
	long n;

	for (int i = 0; numberList[i] && !_isInit; i++)
	{
		if (!checkPosNumbericString(numberList[i]))
			return (0);
		n = atol(numberList[i]);
		if (n > INT_MAX)
			return (pError("number '" + std::string(numberList[i]) + "'out of range", 0));
		_numList.resize(_numList.size() + 1);
		_numVector.resize(_numList.size() + 1);
		_numList.push_back(atoi(numberList[i]));
		_numVector.push_back(atoi(numberList[i]));
	}
	return (1);
}

int	PmergeMe::reinit(char **numberList)
{
	if (!_isInit)
		return (pError("class not initialized, please use init() before using", 0));
	PmergeMe tmp;
	*this = tmp;
	return ((_isInit = init(numberList)));
}

bool PmergeMe::isInitialized() { return (_isInit); }

int	PmergeMe::checkPosNumbericString(std::string num)
{
	if (num.find_first_not_of("-0123456789") != std::string::npos)
		return (pError("number '" + num + "' not recognized", 0));
	if (num.find('-') != std::string::npos || num.length() > 10)
		return (pError("number '" + num + "' out of range", 0));
	return (1);
}

int	PmergeMe::pError(std::string msg, int code)
{
	std::cout << "Error: " << msg << std::endl;
	return (code);
}