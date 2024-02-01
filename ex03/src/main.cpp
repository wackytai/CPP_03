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
	for (int i = 0; i < 5; i++)
	{
		c1.attack(c2.get_name());
		c2.takeDamage(c2.get_attack_damage());		
	}
	c2.beRepaired(5);
	c2.attack(c1.get_name());
	//
	c3.beRepaired(1);
	for (int i = 0; i < 5; i++)
	{
		c3.attack(c4.get_name());
		c4.takeDamage(c3.get_attack_damage());
		c4.beRepaired(c3.get_attack_damage() / 2);		
	}
	c3.set_energy_points(0);
	c3.beRepaired(1);
	c3.attack(c4.get_name());
	c3.highFivesGuys();
	c3.whoAmI();
	return (0);
}