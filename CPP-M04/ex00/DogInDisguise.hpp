#ifndef	DIGSUISED_DOG_H	
# define DIGSUISED_DOG_H

# include "Animalish.hpp"

class DogInDisguise: public Animalish
{
	public:
		DogInDisguise( void );
		DogInDisguise( const DogInDisguise &a);
		DogInDisguise &operator= (const DogInDisguise &a);
		~DogInDisguise( void );
};

#endif