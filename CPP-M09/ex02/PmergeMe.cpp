#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>

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
	std::cout << "Time to process a range of " << _numVector.size() << " elements with std::vector:	" << timeSpent << " ms" << std::endl;
	start = clock();
	sortList();
	timeSpent = (double)(clock() - start ) / clocksPerSubdivision;
	std::cout << "Time to process a range of " << _numList.size() << " elements with std::list:	" << timeSpent << " ms" << std::endl;
	printContainer(_numList);
	
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
	for (std::vector<int>::iterator it = _numVector.begin(); it != _numVector.end(); it++)
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
	for (std::vector<std::pair<int, int> >::iterator it = _vecPairs.begin() + 1; it != _vecPairs.end(); it++)
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
	for (std::vector<std::pair<int, int> >::iterator i = _vecPairs.begin(); i != _vecPairs.end(); i++)
	{
		_numVector.insert(_numVector.begin(), (*i).first);
		if ((*i).second == -1)
			continue ;
		_numVector.insert(std::lower_bound(_numVector.begin(), _numVector.end(), (*i).second), (*i).second);
	}
}

void PmergeMe::insertSort(std::list<int> &a)
{
	std::list<int>::iterator it = a.begin();
	std::list<int>::iterator itk;

	++it;
	for (; it != a.end(); it++)
	{
		itk = --it;
		++it;
		for (; itk != a.begin() && *(++itk) < *(--itk); --itk)
			std::iter_swap(++itk, --itk);
		itk++;
		if (itk != a.begin() && itk != a.end() && *itk < *a.begin())
			std::iter_swap(itk, a.begin());
	}
}

void PmergeMe::divideContainer(std::list<int> &a, std::list<int> &b)
{
	size_t offset;
	std::list<int>::iterator it = a.begin();
	size_t size = a.size();
	
	offset = !(size % 2) ? size / 2 : size / 2 + 1;
	for (; it != a.end() && offset--; it++) { }
	std::copy(it, a.end(), std::back_inserter(b));
	a.erase(it, a.end());
}

void	PmergeMe::divideListPairs()
{
	std::pair<int, int>			tmp;
	std::list<int>::iterator	tmpi;
	for (std::list<int>::iterator it = _numList.begin(); it != _numList.end(); ++it)
	{
		tmpi = it;
		if (++tmpi != _numList.end())
		{
			tmp.first = *(it);
			if (*it > *(++it))
			{
				tmp.second = tmp.first;
				tmp.first = *it;
			}
			else
				tmp.second = *it;
		}
		else
		{
			tmp.first = *it;
			tmp.second = -1;
		}
		_vecPairs.push_back(tmp);
		std::cout << "List pair = { " << tmp.first << ", " << tmp.second << " }" << std::endl;
	}
}

void PmergeMe::insertSortVectorPairs()
{
	std::list<int>::iterator it = a.begin();
	std::list<int>::iterator itk;

	++it;
	for (; it != a.end(); it++)
	{
		itk = --it;
		++it;
		for (; itk != a.begin() && *(++itk) < *(--itk); --itk)
			std::iter_swap(++itk, --itk);
		itk++;
		if (itk != a.begin() && itk != a.end() && *itk < *a.begin())
			std::iter_swap(itk, a.begin());
	}
}

void PmergeMe::sortList()
{
	// std::list<int> tmpList;
	// std::list<int> result;

	if (_numList.size() <= 1)
		return ;
	divideListPairs();
	// insertSort(tmpList);
	insertSort(_numList);
	// _numList.merge(tmpList);
}

int PmergeMe::pError(std::string msg, int code)
{
	std::cout << "Error: " << msg << std::endl;
	return (code);
}