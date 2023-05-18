#ifndef	ANIMALISH_H	
# define ANIMALISH_H

# include <iostream>

class Animalish
{
	protected:
		std::string	_type;
		
	public:
		Animalish( void );
		Animalish( const Animalish &a);
		Animalish &operator= (const Animalish &a);
		~Animalish( void );
		void	makeSound( void ) const;
		const std::string &get_type( void ) const;
};


#endif
