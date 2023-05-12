#include <iostream>
#include <iomanip>
#include "Phonebook.hpp"
#include <string>
#include <stdlib.h>
#include <string.h>

Phonebook::Phonebook(void)
{
	std::cout << "Phonebook initialized" << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Phonebook destroyed" << std::endl;
}

void	Phonebook::add( void )
{
	static int	i;
	std::string strs[5];

	std::cout << "Input contact details" << std::endl << " First name:\t";
	getline(std::cin, strs[0]);
	if (!std::cin.eof()) std::cout << " Last name:\t";
	getline(std::cin, strs[1]);
	if (!std::cin.eof()) std::cout << " Nick name:\t";
	getline(std::cin, strs[2]);
	if (!std::cin.eof()) std::cout << " Phone number:\t";
	getline(std::cin, strs[3]);
	if (!std::cin.eof()) std::cout << " Secret:\t";
	getline(std::cin, strs[4]);
	if (!std::cin.eof() && contacts[i % 8].set_data(strs[0], strs[1], strs[2], strs[3], strs[4]))
		i++;
}

int	Phonebook::_print_all_contacts() const
{
	int	i;
	std::string strs[3];

	std::cout  << std::endl << "|        id|   f. name|   l. name|   n. name|" << std::endl;
	for (i = 0; i < 8; i++)
	{
		if (!this->contacts[i].get_init_value())
			break ;
		std::cout << "|" << std::right << std::setw(10) << i + 1 << "|";
		strs[0] = this->contacts[i].f_name.length() < 10 ?
			this->contacts[i].f_name : this->contacts[i].f_name.substr(0, 9).append(".");
		strs[1] = this->contacts[i].l_name.length() < 10 ?
			this->contacts[i].l_name : this->contacts[i].l_name.substr(0, 9).append(".");
		strs[2] = this->contacts[i].n_name.length() < 10 ?
			this->contacts[i].n_name : this->contacts[i].n_name.substr(0, 9).append(".");
		for (int j = 0; j < 3; j++)
			std::cout << std::right << std::setw(10) << strs[j] << "|";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return (i);
}

int	is_valid_choice(std::string choice, int i)
{
	if (!isdigit(choice[0]) || choice.length() != 1)
		return (0);
	if (atoi(choice.c_str()) > i || atoi(choice.c_str()) < 1 || atoi(choice.c_str()) > 8)
		return (0);
	return (1);
}

void	Phonebook::_select_contact(int i) const
{
	std::string	chosen_contact;

	if (std::cin.eof())
		return ;
	std::cout << "Choose contact to display: ";
	getline(std::cin, chosen_contact);
	if (std::cin.eof())
		return ;
	if (!chosen_contact.compare("EXIT"))
		return ;
	if (is_valid_choice(chosen_contact, i))
		this->contacts[atoi(chosen_contact.c_str()) - 1].print_contact_info();
	else
	{
		std::cout << "Invalid choice" << std::endl;
		this->_print_all_contacts();
		std::cout << "Input \"EXIT\" to go back to main menu" << std::endl;
		this->_select_contact(i);
	}
}

void	Phonebook::search() const
{
	int			i;

	if (!this->contacts[0].get_init_value())
	{
		std::cout << "Contact's list empty" << std::endl;
		return ;
	}
	i = this->_print_all_contacts();
	this->_select_contact(i);		
}