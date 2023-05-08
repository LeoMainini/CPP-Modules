#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H
#include <map>
#include <iostream>

class BitcoinExchange{

	private:
		std::map<std::string, std::string> db;
		int		pError(std::string msg, int code);
		void	init();
		void	initDbEntry(std::string &line);
		int		verifyEntry(std::string &str);
		int		getDateAmount(std::string &line, std::string &date, std::string &amount);
		void	pEntry(std::string &date, float amount, float value);
		int		verifyDate(std::string &date);
		int		checkDateFormat(std::string &y, std::string &m, std::string &d);
		int		verifyAmount(std::string &amount);
		void	printLineCalculation(std::string &line);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cp);
		BitcoinExchange &operator=(const BitcoinExchange &as);
		~BitcoinExchange();
		int	printCalcdOutput(std::string ifilename);
};

#endif