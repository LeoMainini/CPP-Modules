#ifndef HUMAN_A_H
# define HUMAN_A_H

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon		&weapon;
	public:
		HumanA(std::string name, Weapon &wep);
		~HumanA(void);
		void	attack( void ) const;
};

#endif