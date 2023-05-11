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
	std::clock_t start = clock();
	int		secSubdivisions = 1;
	long	clocks_per_mcs = CLOCKS_PER_SEC * (1.0 / secSubdivisions);

	std::cout << "clocks  = " << start << std::endl;
	if (!isInitialized())
		return ((void)pError("class not initialized, please use init() before using", 0));
	std::cout << std::fixed;

	sortVector();
	std::cout <<"Time to complete = " << (double)(clock() - start ) / clocks_per_mcs << std::endl;
	start = clock();
	sortList();
	std::cout <<"Time to complete = " << (double)(clock() - start ) / clocks_per_mcs << std::endl;
	
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

void PmergeMe::divideContainer(std::vector<int> &a, std::vector<int> &b)
{
	size_t offset;
	size_t size = a.size();

	offset = !(size % 2) ? size / 2 : size / 2 + 1;
	std::copy(a.begin() + offset, a.end(), std::back_inserter(b));
	a.erase(a.begin() + offset, a.end());
}

void PmergeMe::insertSort(std::vector<int> &a)
{
	for (std::vector<int>::iterator it = a.begin() + 1; it != a.end(); it++)
		for (std::vector<int>::iterator itk = it - 1; itk >= a.begin() && *itk > *(itk + 1); --itk)
			std::iter_swap(itk, itk + 1);
}

void PmergeMe::sortVector()
{
	std::vector<int> tmpVector;
	std::vector<int> result;

	if (_numVector.size() == 1)
		return ;
	divideContainer(_numVector, tmpVector);
	insertSort(_numVector);
	insertSort(tmpVector);
	std::merge(_numVector.begin(), _numVector.end(), tmpVector.begin(), tmpVector.end(), std::back_inserter(result));
	_numVector.erase(_numVector.begin(), _numVector.end());
	std::copy(result.begin(), result.end(), std::back_inserter(_numVector));
	// for (std::vector<int>::iterator it = _numVector.begin(); it != _numVector.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
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

void PmergeMe::sortList()
{
	std::list<int> tmpList;
	std::list<int> result;

	if (_numList.size() == 1)
		return ;
	divideContainer(_numList, tmpList);
	insertSort(tmpList);
	insertSort(_numList);
	_numList.merge(tmpList);
	// for (std::list<int>::iterator it = _numList.begin(); it != _numList.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
}

int PmergeMe::pError(std::string msg, int code)
{
	std::cout << "Error: " << msg << std::endl;
	return (code);
}