#ifndef P_MERGE_ME_H
#define P_MERGE_ME_H
#include <vector>
#include <list>
#include <iostream>

class PmergeMe {
	private:
		bool				_isInit;
		std::vector<int>	_numVector;
		std::list<int>		_numList;
		std::vector<std::pair<int, int> >	_vecPairs;
		std::list<std::pair<int, int> >		_listPairs;
		int		checkPosNumbericString(std::string num);
		int		pError(std::string msg, int code);
		void	insertSortVectorPairs();
		void	insertSort(std::list<int> &a);
		void	divideVectorPairs();
		void	divideListPairs();
		void	insertSortListPairs();
		void	divideContainer(std::list<int> &a, std::list<int> &b);
		void	sortVector();
		void	sortList();

	public:
		int		init(char **numberList);
		int		reinit(char **numberList);
		bool	isInitialized();
		void	runTest();
		PmergeMe();
		PmergeMe(char **numberList);
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator= (const PmergeMe &as);
		~PmergeMe();

};

template <class T>
void	printContainer(const T &c)
{
	typedef typename T::const_iterator citer;
	size_t	i = 0;
	citer it;

	for (it = c.begin() ; it != c.end() && i < 5; it++, i++)
		std::cout << *it << " ";
	if (c.size() > 5)
		std::cout << "[...]";
	else if (it != c.end())
		std::cout << *it;
	std::cout << std::endl;
}

template <class T>
typename T::iterator nextIt(T &o, typename T::iterator it)
{
	typedef typename T::iterator iter;
	iter tmp = it;
	if (tmp == o.end() || ++tmp == o.end())
		return (o.end());
	return (tmp);
}

template <class T>
typename T::iterator prevIt(T &o, typename T::iterator it)
{
	typedef typename T::iterator iter;
	iter tmp = it;
	if (tmp == o.end())
	{
		for (iter tmp2 = o.begin(); tmp2 != o.end() ; tmp2++)
			tmp = tmp2;
		return (tmp);
	}
	if (tmp == o.begin())
		return (o.end());
	return (--tmp);
}

template <class T, class C>
void	insertSubContainerPairs(T &c, C &sc)
{
	typedef typename C::iterator subIter;

	for (subIter i = sc.begin(); i != sc.end(); i++)
	{
		c.insert(c.begin(), (*i).first);
		if ((*i).second == -1)
			continue ;
		c.insert(std::lower_bound(c.begin(), c.end(), (*i).second), (*i).second);
	}
}

#endif