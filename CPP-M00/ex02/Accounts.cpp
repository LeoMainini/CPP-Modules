#include "Account.hpp"
#include <iostream>
#include <time.h>

//static class members are like global vars in C they need to be declared for the
// compiler to know they exist across files

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// static variables in c++ behave much like a mix of static and global variables
// their value persists through multiple instances of a class, and is global to all instances of it

int		Account::getNbAccounts( void ) { return (t::_nbAccounts);}

int		Account::getTotalAmount( void ) { return (t::_totalAmount); }

int		Account::getNbDeposits( void ) { return (t::_totalNbDeposits); }

int		Account::getNbWithdrawals( void ) { return (t::_totalNbWithdrawals); }

void	Account::displayAccountsInfos( void ) 
{
	t::_displayTimestamp();
	std::cout << "accounts:" << t::getNbAccounts() 
		<< ";total:" << t::getTotalAmount() << ";deposits:"
		<< t::getNbDeposits() << ";withdrawals:" << t::getNbWithdrawals() 
		<< std::endl;
}

Account::Account( void )
{
	return ;	
}

Account::Account( int initial_deposit ):
	_accountIndex(t::_nbAccounts++), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0) 
{
	t::_totalAmount += this->_amount;
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit
		<< ";created" <<std::endl;
}

Account::~Account( void ) 
{
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";closed" << std::endl;
}

void	Account::_displayTimestamp( void ) 
{
	time_t	current_time;
	tm		*dt_data;
	char	dt_str[18];

	time(&current_time);
	dt_data = localtime(&current_time);
	strftime(dt_str, 17, "%Y%m%d_%H%M%S", dt_data);
	dt_str[17] = 0;
	std::cout << "[" << dt_str << "] ";
}

void	Account::displayStatus() const 
{
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount 
		<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

void	Account::makeDeposit( int deposit ) {
	int	p_amount;

	p_amount = this->_amount;
	t::_totalNbDeposits++;
	this->_amount = deposit >= 0 ? this->_amount + deposit : this->_amount;
	t::_totalAmount += this->_amount - p_amount;
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
		<< ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" 
		<< this->_nbDeposits << std::endl;
}

int		Account::checkAmount( void ) const {
	if (this->_amount < 0)
		std::cout << "withdrawal:refused" << std::endl;
	return (this->_amount);
}

bool	Account::makeWithdrawal( int withdrawl ) {
	int	p_amount;
	

	p_amount = this->_amount;
	this->_amount -= withdrawl;
	t::_displayTimestamp();
	std::cout << "p_amount:" << p_amount << ";";
	if (checkAmount() < 0)
	{
		this->_amount = p_amount;
		return (false);
	}
	else
	{
		this->_nbWithdrawals++;
		t::_totalNbWithdrawals += 1;
		t::_totalAmount -= withdrawl;
		std::cout << ";withdrawal:" << withdrawl << ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}