#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
}