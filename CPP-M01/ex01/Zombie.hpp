#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {

public:

	std::string name;
	int			index;

	Zombie(std::string name);
	Zombie( void );
	~Zombie( void );

	void	announce( void ) const;
	int		getHordeSize( void ) const;
	void	incHordeSize( void );

private:
	static int	_horde_size;

};

#endif