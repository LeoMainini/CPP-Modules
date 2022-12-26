#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {

public:

	std::string name;

	Zombie(std::string name);
	~Zombie( void );

	void	announce( void );

};

#endif