#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.hpp"

class Phonebook {

public:

	Contact contacts[8];

	Phonebook( void );
	~Phonebook( void );

	void	search( void ) const;
	void	add( void );

private:
	int		_print_all_contacts() const;
	void	_select_contact(int i) const;

};

#endif