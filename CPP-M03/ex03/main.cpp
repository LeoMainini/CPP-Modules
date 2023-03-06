#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void )
{
	{
		ClapTrap	ct("gajo 1");
		ClapTrap	ct1(ct);
		ClapTrap	ct2("gajo 2");
		ct = ct2;
		ct.attack("lol");
		ct.attack("lol");
		ct.attack("lol");
		ct.attack("lol");
		ct.attack("lol");
		ct.takeDamage(2);
		ct.takeDamage(2);
		ct.takeDamage(2);
		ct.beRepaired(2);
		ct.beRepaired(2);
		ct.beRepaired(2);
		ct.attack("lol");
		ct.attack("lol");
		ct.attack("lol");
		ct.attack("lol");
		ct.attack("lol");
		ct.takeDamage(2);
		ct.takeDamage(2);
		ct.takeDamage(2);
		ct.beRepaired(2);
		ct.beRepaired(2);
		ct.beRepaired(2);
	}
	std::cout << std::endl << "SCAV TIME" << std::endl << std::endl;
	{
		ScavTrap	st("gajo 1");
		ScavTrap	st1(st);
		ScavTrap	st2("gajo 2");
		st = st2;
		st.attack("lol");
		st.attack("lol");
		st.attack("lol");
		st.attack("lol");
		st.attack("lol");
		st.takeDamage(2);
		st.takeDamage(2);
		st.takeDamage(2);
		st.beRepaired(2);
		st.beRepaired(2);
		st.beRepaired(2);
		st.attack("lol");
		st.attack("lol");
		st.attack("lol");
		st.attack("lol");
		st.attack("lol");
		st.takeDamage(2);
		st.takeDamage(2);
		st.takeDamage(2);
		st.beRepaired(2);
		st.beRepaired(2);
		st.beRepaired(2);
		st.guardGate();
	}
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
	{
		DiamondTrap dt("ola");
		DiamondTrap dt2("ola2");
		dt2.beRepaired(5);
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
}