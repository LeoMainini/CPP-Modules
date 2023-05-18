#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	FragTrap	ft("gajo 1");
	FragTrap	ft1(ft);
	FragTrap	ft2("gajo 2");
	ft = ft2;
	ft.attack("lol");
	ft.attack("lol");
	ft.attack("lol");
	ft.attack("lol");
	ft.attack("lol");
	ft.takeDamage(2);
	ft.takeDamage(2);
	ft.takeDamage(2);
	ft.beRepaired(2);
	ft.beRepaired(2);
	ft.beRepaired(2);
	ft.attack("lol");
	ft.attack("lol");
	ft.attack("lol");
	ft.attack("lol");
	ft.attack("lol");
	ft.takeDamage(2);
	ft.takeDamage(2);
	ft.takeDamage(2);
	ft.beRepaired(2);
	ft.beRepaired(2);
	ft.beRepaired(2);
	ft.highFivesGuys();
}