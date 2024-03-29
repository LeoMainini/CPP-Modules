#ifndef HUMAN_B_H
# define HUMAN_B_H

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon		*weapon;
	public:
		HumanB( std::string name );
		~HumanB( void );
		void	setWeapon(Weapon &wep);
		void	attack( void ) const;
};

#endif