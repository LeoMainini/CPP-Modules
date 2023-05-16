#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {

public:
	Zombie(std::string name);
	Zombie( void );
	~Zombie( void );
	void	initName(std::string name);
	void	announce( void ) const;
	int		getHordeSize( void ) const;
	void	incHordeSize( void );

private:
	std::string name;
	int			index;
	static int	_horde_size;

};

#endif