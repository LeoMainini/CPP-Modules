#include "BitcoinExchange.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime>
#include <climits>

//TODO:
//FIND CLOSEST DATE WITH STRING COMPARING (== = FOUND) (> = AFTER) (< = BEFORE)
//CALCULATE AND PRINT PRICES
//PRINT SPECIFIED ERROR MESSAGES

BitcoinExchange::BitcoinExchange() {
	init();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp) {
	*this = cp;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &as) {
	BitcoinExchange copy = const_cast<BitcoinExchange &>(as);
	if (this != &as)
	{
		for (std::map<std::string,std::string>::iterator it = db.begin();
			it != db.end(); it++)
			db.erase(it);
		for (std::map<std::string,std::string>::iterator it = copy.db.begin();
			it != copy.db.end(); it++)
			db[it->first] = it->second;
	}
	return (*this);
}

int verifyAmount(std::string &amount)
{
	if (amount.find_first_of(".") != amount.find_last_of(".")
		|| amount.find_first_of("0123456789") > amount.find('.')
		|| amount.find_last_of("0123456789") > amount.find('.')
		|| amount.find_first_not_of(".0123456789") != std::string::npos)
		return (0);
	if (amount.find(".") == std::string::npos)
	{
		long n = std::atol(amount.c_str());
		if (n > INT_MAX || n < 0 || amount.length() > 10)
			return (0);
		return (1);
	}
	float fn = strtof(amount.c_str(), 0);
	if (errno == ERANGE || fn < 0)
		return (0);
	return (1);
}

int	checkDateFormat(std::string &y, std::string &m, std::string &d)
{
	std::time_t time = std::time(NULL);
	std::tm *dateTime = std::localtime(&time);
	int year = std::atoi(y.c_str());
	int month = std::atoi(m.c_str());
	int day = std::atoi(d.c_str());

	if (year < 2009 || year > dateTime->tm_year + 1900)
	 	return (0);
	if (month < 1 || month > 12
	 || (year == dateTime->tm_year + 1900 && month > dateTime->tm_mon + 1))
	 	return (0);
	if (day < 1 || day > 31 || (year == dateTime->tm_year + 1900
	 	&& month == dateTime->tm_mon + 1 && day > dateTime->tm_mday))
	 	return (0);
	dateTime->tm_year = year - 1900;
	dateTime->tm_mon = month - 1;
	dateTime->tm_mday = day;
	mktime (dateTime);
	if (dateTime->tm_year == year - 1900
		&& dateTime->tm_mon == month - 1
		&& dateTime->tm_mday == day)
		return (1);
	return (0);
}

int	verifyDate(std::string &date)
{
	std::stringstream dates(date);
	std::string year;
	std::string month;
	std::string day;
	getline(dates, year, '-');
	if(dates.eof() || year.length() != 4
		|| year.find_last_not_of("0123456789") != std::string::npos)
		return (0);
	getline(dates, month, '-');
	if(dates.eof() || month.length() != 2
		|| month.find_last_not_of("0123456789")!= std::string::npos)
		return (0);
	getline(dates, day);
	if(!dates.eof() || day.length() != 2
		|| day.find_last_not_of("0123456789")!= std::string::npos)
		return (0);

	return (checkDateFormat(year, month, day));
}

int	verifyEntry(std::string &str)
{
	std::stringstream strs(str);
	std::string date;
	std::string amount;

	getline(strs, date, '|');
	if (strs.eof())
		return (0);
	std::remove(date.begin(), date.end(), ' ');
	std::remove(date.begin(), date.end(), '	');
	getline(strs, amount);
	if (!strs.eof())
		return (0);
	std::remove(amount.begin(), amount.end(), ' ');
	std::remove(amount.begin(), amount.end(), '	');
	if (!verifyDate(date) || !verifyAmount(amount))
		return (0);
	return (1);
}

BitcoinExchange::~BitcoinExchange() { }

void	BitcoinExchange::initDbEntry(std::string &line){
	std::istringstream dbEntry(line);
	std::string date;
	std::string amount;
	std::getline(dbEntry, date, ',');
	std::getline(dbEntry, amount, ',');
	db[date] = amount;
	std::cout << date << ": " << db.find(date)->second << std::endl;
}


void	BitcoinExchange::init() {
	std::ifstream dbfile;
	dbfile.open("data.csv");
	if (dbfile.fail())
		throw (std::ios_base::failure("Failed to open file"));
	for(std::string line; std::getline(dbfile, line, '\n');)
		initDbEntry(line);
}