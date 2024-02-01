#include "../inc/ScavTrap.hpp"

int main(void)
{
	ScavTrap	c1;
	ScavTrap	c2("Gary");
	ScavTrap	c3(c2);
	ScavTrap	c4;

	c4 = c1;
	for (int i = 0; i < 6; i++)
	{
		c1.attack(c2.getName());
		c2.takeDamage(c2.getDamage());		
	}
	c2.beRepaired(5);
	c2.attack(c1.getName());
	//
	c3.beRepaired(1);
	for (int i = 0; i < 6; i++)
	{
		c3.attack(c4.getName());
		c4.takeDamage(c3.getDamage());
		c4.beRepaired(c3.getDamage() / 2);		
	}
	for (int i = 0; i < 44; i++)
		c3.attack("Closest wall");
	c3.beRepaired(1);
	c3.attack(c4.getName());
	c3.guardGate();
	c3.guardGate();
	return (0);
}