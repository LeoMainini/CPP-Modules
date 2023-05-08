#include "BitcoinExchange.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime>
#include <climits>
#include <iomanip>

BitcoinExchange::BitcoinExchange()
{
	init();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp)
{
	*this = cp;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &as)
{
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

BitcoinExchange::~BitcoinExchange()
{ }

void	BitcoinExchange::init()
{
	std::ifstream	dbfile;
	std::string		line;

	dbfile.open("data.csv");
	if (dbfile.fail())
		throw (std::ios_base::failure("Failed to open database file"));
	std::getline(dbfile, line, '\n');
	while(std::getline(dbfile, line, '\n'))
		initDbEntry(line);
}

void	BitcoinExchange::initDbEntry(std::string &line)
{
	std::istringstream dbEntry(line);
	std::string date;
	std::string amount;
	std::getline(dbEntry, date, ',');
	std::getline(dbEntry, amount, ',');
	db[date] = amount.empty() ? "0" : amount;
}

int	BitcoinExchange::printCalcdOutput(std::string ifilename)
{
	std::ifstream	inputFile;
	std::string		line, fLineDate, fLineAmount;

	inputFile.open(ifilename.c_str());
	if (inputFile.fail())
		return (pError("could not open file => " + ifilename, 0));
	std::getline(inputFile, line, '\n');
	getDateAmount(line, fLineDate, fLineAmount);
	if (fLineDate.compare("date"))
		if (verifyEntry(line))
			printLineCalculation(line);
	while (std::getline(inputFile, line, '\n'))
		if (verifyEntry(line))
			printLineCalculation(line);
	return (0);
}

void	BitcoinExchange::printLineCalculation(std::string &line)
{
	std::string	amount, date;
	std::map<std::string, std::string>::iterator it = db.begin();

	getDateAmount(line, date, amount);
	if (it->first > date)
		return (pEntry(date, strtof(amount.c_str(), 0), strtof(it->second.c_str(), 0)));
	for ( ; it != db.end() && it->first < date; it++) {}
	if ( it == db.end() || it->first > date)
		it--;
	pEntry(date, strtof(amount.c_str(), 0), strtof(it->second.c_str(), 0));
}

int	BitcoinExchange::pError(std::string msg, int code)
{
	std::cout << "Error: " << msg << std::endl;
	return (code);
}

void	BitcoinExchange::pEntry(std::string &date, float amount, float value)
{
	std::cout << date << " => " <<  amount * value << std::endl;
}

int	BitcoinExchange::verifyEntry(std::string &str)
{
	std::string date;
	std::string amount;

	if (!getDateAmount(str, date, amount))
		return (0);
	if (!verifyDate(date) || !verifyAmount(amount))
		return (0);
	return (1);
}

int	BitcoinExchange::getDateAmount(std::string &str, std::string &date, std::string &amount)
{
	std::stringstream strs(str);

	getline(strs, date, '|');
	if (strs.eof())
		return (pError("bad input => " + str, 0));
	std::remove_if(date.begin(), date.end(), ::isspace), date.end();
	getline(strs, amount);
	if (!strs.eof())
		return (pError("bad input => " + str, 0));
	amount.erase(std::remove_if(amount.begin(), amount.end(), ::isspace), amount.end());
	date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());
	return (1);
}

int BitcoinExchange::verifyAmount(std::string &amount)
{
	long n;
	float fn;

	if ((amount.find('.') != std::string::npos && (amount.find_first_of(".") != amount.find_last_of(".")
		|| amount.find_first_of("0123456789") > amount.find('.')
		|| amount.find_last_of("0123456789") < amount.find('.')))
		|| amount.find_first_not_of(".-0123456789") != std::string::npos)
		return (pError("bad amount input => " + amount + "-", 0));

	if (amount.find(".") == std::string::npos)
	{
		n = std::atol(amount.c_str());
		if (n > INT_MAX || amount.length() > 10)
			return (pError("too large a number => " + amount, 0));
		if ( n < 0 )
			return (pError("not a positive number => " + amount, 0));
		return (1);
	}
	fn = strtof(amount.c_str(), 0);
	if (errno == ERANGE)
		return (pError("too large a number => " + amount, 0));
	if (fn < 0)
		return (pError("not a positive number => " + amount, 0));
	return (1);
}

int	BitcoinExchange::checkDateFormat(std::string &y, std::string &m, std::string &d)
{
	std::time_t time = std::time(NULL);
	std::tm *dateTime = std::localtime(&time);
	int year = std::atoi(y.c_str());
	int month = std::atoi(m.c_str());
	int day = std::atoi(d.c_str());

	if (year < 2009 || year > dateTime->tm_year + 1900)
		return (pError("bad date input => " + y + " out of range", 0));
	if (month < 1 || month > 12
	 || (year == dateTime->tm_year + 1900 && month > dateTime->tm_mon + 1))
		return (pError("bad date input => " + y + "-" + m + "-" + d + " in the future", 0));
	if (day < 1 || day > 31 || (year == dateTime->tm_year + 1900
	 	&& month == dateTime->tm_mon + 1 && day > dateTime->tm_mday))
		return (pError("bad date input => " + y + "-" + m + "-" + d + " in the future", 0));
	dateTime->tm_year = year - 1900;
	dateTime->tm_mon = month - 1;
	dateTime->tm_mday = day;
	mktime (dateTime);
	if (dateTime->tm_year == year - 1900
		&& dateTime->tm_mon == month - 1
		&& dateTime->tm_mday == day)
		return (1);
	return (pError("bad date input => " + y + "-" + m + "-" + d, 0));
}

int	BitcoinExchange::verifyDate(std::string &date)
{
	std::stringstream dates(date);
	std::string year, month, day;

	getline(dates, year, '-');
	if(dates.eof() || year.length() != 4
		|| year.find_last_not_of("0123456789") != std::string::npos)
		return (pError("bad date input => " + date, 0));
	getline(dates, month, '-');
	if(dates.eof() || month.length() != 2
		|| month.find_last_not_of("0123456789")!= std::string::npos)
		return (pError("bad date input => " + date, 0));
	getline(dates, day);
	if(!dates.eof() || day.length() != 2
		|| day.find_last_not_of("0123456789") != std::string::npos)
		return (pError("bad date input => " + day + date, 0));

	return (checkDateFormat(year, month, day));
}
