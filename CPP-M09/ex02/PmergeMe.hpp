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
	public:
		int	init(char **numberList);
		int	reinit(char **numberList);
		bool isInitialized();
		PmergeMe();
		PmergeMe(char **numberList);
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator= (const PmergeMe &as);
		~PmergeMe();

};

#endif