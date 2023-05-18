#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void )
{
	//energy should be - scav - 50
	//attack should be - frag - 30
	//health should be - frag - 100
	DiamondTrap dt("ola");
	DiamondTrap dt2("ola2");
	dt2.beRepaired(0);
	dt2.beRepaired(5);
	dt2.beRepaired(5);
	dt2.beRepaired(5);
	dt2.beRepaired(5);
	dt2.beRepaired(5);
	dt = dt2;
	dt.beRepaired(5);
	dt.attack("lol");
	dt.whoAmI();
}