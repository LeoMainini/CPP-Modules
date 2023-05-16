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
		void	insertSortVectorPairs();
		void	divideContainer(std::list<int> &a, std::list<int> &b);
		void	sortVector();
		void	sortList();
		template <class T>
		void	printContainer(const T &c)
		{
			typedef typename T::const_iterator citer;
			size_t	i = 0;
			citer it;

			for (it = c.begin() ; it != c.end(); it++, i++)
				std::cout << *it << " ";
			if (c.size() > 5)
				std::cout << "[...]";
			else if (it != c.end())
				std::cout << *it;
			std::cout << std::endl;

		}

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

#endif