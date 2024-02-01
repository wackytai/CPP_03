#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int main(void)
{
    FragTrap	c1;
	FragTrap	c2("Larry");
	FragTrap	c3(c1);
	FragTrap	c4;

	c4 = c2;
	for (int i = 0; i < 5; i++)
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
	for (int i = 0; i < 95; i++)
		c3.attack("Random wall");
	c3.beRepaired(1);
	c3.attack(c4.getName());
	c3.highFivesGuys();
	return (0);
}