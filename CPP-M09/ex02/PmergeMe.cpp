#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>
// #include "biDirIterFunctions.hpp"

// Must init after calling constructor
PmergeMe::PmergeMe() : _isInit(false) {}

PmergeMe::PmergeMe(char **numberList) : _isInit(false)
{
	if (!numberList && pError("Invalid string array pointer passed to constructor", 0))
		return;
	_isInit = init(numberList);
}

PmergeMe::PmergeMe(const PmergeMe &cp)
{
	*this = cp;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &as)
{
	if (&as != this && as._isInit)
	{
		_numVector = as._numVector;
		_numList = as._numList;
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

PmergeMe::~PmergeMe() {}

int PmergeMe::init(char **numberList)
{
	long n;

	for (int i = 0; numberList[i] && !_isInit; i++)
	{
		if (!checkPosNumbericString(numberList[i]))
			return (0);
		n = atol(numberList[i]);
		if (n > INT_MAX)
			return (pError("number '" + std::string(numberList[i]) + "'out of range", 0));
		_numList.push_back(atoi(numberList[i]));
		_numVector.push_back(atoi(numberList[i]));
	}
	return (1);
}

int PmergeMe::reinit(char **numberList)
{
	if (!_isInit)
		return (pError("class not initialized, please use init() before using", 0));
	PmergeMe tmp;
	*this = tmp;
	return ((_isInit = init(numberList)));
}

void	PmergeMe::runTest()
{
	std::clock_t start;
	int		secSubdivisions = 1000;
	long	clocksPerSubdivision = CLOCKS_PER_SEC * (1.0 / secSubdivisions);
	double	timeSpent;


	if (!isInitialized())
		return ;
	std::cout << std::fixed;
	std::cout << "Before:	";
	printContainer(_numVector);
	std::cout << "After:	";
	start = clock();
	sortVector();
	timeSpent = (double)(clock() - start ) / clocksPerSubdivision;
	printContainer(_numVector);
	std::cout << "Time to process a range of " << _numVector.size() << " elements with std::vector:	" << timeSpent << " ms" << std::endl;
	start = clock();
	sortList();
	timeSpent = (double)(clock() - start ) / clocksPerSubdivision;
	std::cout << "Time to process a range of " << _numList.size() << " elements with std::list:	" << timeSpent << " ms" << std::endl;
}

bool PmergeMe::isInitialized() { return (_isInit); }

int PmergeMe::checkPosNumbericString(std::string num)
{
	if (num.find_first_not_of("-0123456789") != std::string::npos)
		return (pError("number '" + num + "' not recognized", 0));
	if (num.find('-') != std::string::npos || num.length() > 10)
		return (pError("number '" + num + "' out of range", 0));
	return (1);
}

void PmergeMe::divideVectorPairs()
{
	std::pair<int, int> tmp;
	_vecPairs.reserve(_numVector.size() / 2 + 1);
	for (std::vector<int>::iterator it = _numVector.begin(); it != _numVector.end(); ++it)
	{
		if (it + 1 != _numVector.end())
		{
			tmp.first = *it > *(it + 1) ? *(it + 1) : *it ;
			tmp.second = *it < *(it + 1) ? *(it + 1) : *it ;
			it++;
		}
		else
		{
			tmp.first = *it;
			tmp.second = -1;
		}
		_vecPairs.push_back(tmp);
	}
}

void PmergeMe::insertSortVectorPairs()
{
	for (std::vector<std::pair<int, int> >::iterator it = _vecPairs.begin() + 1; it != _vecPairs.end(); ++it)
 		for (std::vector<std::pair<int, int> >::iterator itk = it - 1; itk >= _vecPairs.begin() && (*itk).first < (*(itk + 1)).first; --itk)
			std::iter_swap(itk, itk + 1);
}

void PmergeMe::sortVector()
{
	if (_numVector.size() <= 1)
		return ;
	divideVectorPairs();
	insertSortVectorPairs();
	_numVector.erase(_numVector.begin(), _numVector.end());
	insertSubContainerPairs(_numVector, _vecPairs);
}

void	PmergeMe::divideListPairs()
{
	std::pair<int, int> tmp;
	for (std::list<int>::iterator it = _numList.begin(); it != _numList.end(); ++it)
	{
		if (::nextIt(_numList, it) != _numList.end())
		{
			tmp.first = *it > *(::nextIt(_numList, it)) ? *(::nextIt(_numList, it)) : *it ;
			tmp.second = *it < *(::nextIt(_numList, it)) ? *(::nextIt(_numList, it)) : *it ;
			it++;
		}
		else
		{
			tmp.first = *it;
			tmp.second = -1;
		}
		_listPairs.push_back(tmp);
	}
}

void PmergeMe::insertSortListPairs()
{
	typedef std::list<std::pair<int, int> >::iterator iter;
	iter itk;

	for (iter it = ::nextIt(_listPairs, _listPairs.begin()); it != _listPairs.end(); ++it)
	{
		itk = ::prevIt(_listPairs, it);
		for ( ; itk != _listPairs.begin() && *itk < *::nextIt(_listPairs, itk); --itk)
			std::iter_swap(itk, ::nextIt(_listPairs, itk));
		++itk;
		if (itk != _listPairs.begin() && itk != _listPairs.end() && *itk > *_listPairs.begin())
			std::iter_swap(itk, _listPairs.begin());
	}
}

void PmergeMe::sortList()
{
	if (_numList.size() <= 1)
		return ;
	divideListPairs();
	insertSortListPairs();
	_numList.erase(_numList.begin(), _numList.end());
	insertSubContainerPairs(_numList, _listPairs);

}

int PmergeMe::pError(std::string msg, int code)
{
	std::cout << "Error: " << msg << std::endl;
	return (code);
}