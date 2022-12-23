#include <iostream>
#include "Contact.hpp"
#include <string>
#include <string.h>

Contact::Contact(void)
{
	this->_initialized = false;
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::_set_secret(std::string secret)
{
	this->_secret = secret;
	return ;
}
bool	Contact::is_valid_info(std::string f, std::string l, std::string nick,
	std::string pn, std::string secret) const
{
	bool	has_nums;

	if (f.empty() || l.empty() || nick.empty() || secret.empty() || pn.empty())
	{
		std::cout << "Fields cannot be empty" << std::endl;
		return (false);
	}
	has_nums = false;
	for (int i = 0; pn[i]; i++)
		if (isdigit(pn[i]))
			has_nums = true;
	if (pn.length() < 6 || !has_nums)
	{
		std::cout << "Phone number must be at least 6 characters and contain numbers" << std::endl;
		return (false);
	}
	return (true);
}

int	Contact::set_data(std::string f, std::string l, std::string nick,
	std::string pn, std::string secret)
{
	if (!this->is_valid_info(f, l, nick, pn, secret))
		return 0;
	this->f_name = f;
	this->l_name = l;
	this->n_name = nick;
	this->ph_number = pn;
	this->_set_secret(secret);
	this->_initialized = true;
	return 1;
}

void	Contact::print_contact_info() const
{
	std::cout << "First name:	" << this->f_name << std::endl;
	std::cout << "Last name:	" << this->l_name << std::endl;
	std::cout << "Nick name:	" << this->n_name << std::endl;
	std::cout << "Phone number:	" << this->ph_number << std::endl;
	std::cout << "Secret:		" << this->_secret << std::endl;

}

bool	Contact::get_init_value() const { return this->_initialized; }