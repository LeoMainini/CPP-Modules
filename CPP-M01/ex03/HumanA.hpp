#ifndef HUMAN_A_H
# define HUMAN_A_H

# include "Weapon.hpp"

class HumanA
{

	public:
		std::string name;
		Weapon		&weapon;

		HumanA(std::string name, Weapon &wep);
		~HumanA(void);
		void	attack( void ) const;

};

#endif