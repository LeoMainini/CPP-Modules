#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H
#include <map>
#include <iostream>

class BitcoinExchange{

	private:
		std::map<std::string, std::string> db;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cp);
		BitcoinExchange &operator=(const BitcoinExchange &as);
		~BitcoinExchange();
		void	init();
		void	initDbEntry(std::string &line);

};

#endif