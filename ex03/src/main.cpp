#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int main(void)
{
    DiamondTrap	c1;
	DiamondTrap	c2("Jerry");
	DiamondTrap	c3(c1);
	DiamondTrap	c4;
	
	c4 = c2;
	c1.showStats();
	c2.showStats();
	c3.showStats();
	c4.showStats();
/* 	for (int i = 0; i < 5; i++)
	{
		c1.attack(c2.getName());
		c2.takeDamage(c2.getDamage());		
	}
	c2.beRepaired(5);
	c2.attack(c1.getName());
	//
	c3.beRepaired(1);
	for (int i = 0; i < 5; i++)
	{
		c3.attack(c4.getName());
		c4.takeDamage(c3.getDamage());
		c4.beRepaired(c3.getDamage() / 2);		
	}
	c3.setEnergy(0);
	c3.beRepaired(1);
	c3.attack(c4.getName());
	c3.highFivesGuys();
	c3.whoAmI(); */
	return (0);
}