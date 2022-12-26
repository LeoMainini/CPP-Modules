#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// Whilst both classes NEED to accept a reference to club - as they both need the adress of club
// only HumanA saves it as a reference, HumanB saves it as a pointer in the case where a weapon
// isnt provided, references need a initial value to be pointed to, a pointer can point to NULL
// club cant be passed as accepted into Human classes as just an object since the adress of the value passed isnt the same in diferent scopes  

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
		{
		Weapon club = Weapon("sloppy ");
		HumanB jim("Poor Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
	}
return 0;
}