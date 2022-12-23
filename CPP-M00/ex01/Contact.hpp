#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>
# include <string.h>

class Contact {

public:

	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string	ph_number;

	Contact(void);
	~Contact(void);

	int	set_data(std::string f, std::string l, std::string nick,
		std::string pn, std::string secret);
	void	set_secret(std::string secret);
	bool	get_init_value() const;
	void	print_contact_info() const;


private:
	void	_set_secret(std::string secret);
	std::string _secret;
	bool		_initialized;
	bool		is_valid_info(std::string f, std::string l,
		std::string nick, std::string pn, std::string secret) const;
};

#endif