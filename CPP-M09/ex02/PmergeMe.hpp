#ifndef P_MERGE_ME_H
#define P_MERGE_ME_H
#include <vector>
#include <list>
#include <iostream>

class PmergeMe {
	private:
		std::vector<int>	_numVector;
		std::list<int>		_numList;
		bool				_isInit;
		int		checkPosNumbericString(std::string num);
		int		pError(std::string msg, int code);
		void	insertSort(std::vector<int> &a);
		void	insertSort(std::list<int> &a);
		void	divideContainer(std::vector<int> &a, std::vector<int> &b);
		void	divideContainer(std::list<int> &a, std::list<int> &b);
		void	sortVector();
		void	sortList();
		template <class T>
		void	printContainer(const T &c)
		{
			typedef typename T::const_iterator citer;
			size_t	i = 0;
			citer it;

			for (it = c.begin() ; it != c.end() && i < 4; it++, i++)
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