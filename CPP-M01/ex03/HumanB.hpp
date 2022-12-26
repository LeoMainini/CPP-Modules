#ifndef HUMAN_B_H
# define HUMAN_B_H

#include "Weapon.hpp"

class HumanB
{
	public:
		
		std::string name;
		Weapon		*weapon;
		
		HumanB( std::string name );
		~HumanB( void );
		void	setWeapon(Weapon &wep);
		void	attack( void ) const;


};

#endif