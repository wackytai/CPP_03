#include "../inc/ClapTrap.hpp"

int main(void)
{
    ClapTrap	c1;
	ClapTrap	c2("base model");
	ClapTrap	c3(c2);
	ClapTrap	c4;

	c4 = c1;
	c1.attack(c2.getName());
	c2.takeDamage(6);
	c1.attack(c2.getName());
	c2.takeDamage(6);
	c1.attack(c2.getName());
	c2.takeDamage(6);
	c2.beRepaired(5);
	c2.attack(c1.getName());
	//
	c3.beRepaired(1);
	for (int i = 0; i < 11; i++)
	{
		c3.attack(c4.getName());
		c4.takeDamage(2);
		c4.beRepaired(1);		
	}
	c3.beRepaired(1);
	return (0);
}