#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    setHealth(FragTrap::HP);
    setEnergy(ScavTrap::EN);
    setDamage(FragTrap::DAM);
    _name = getName() + "_clap_name";
    std::cout << getName() << ": " << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &object ) : ClapTrap(), ScavTrap(), FragTrap()
{
    setName(object.getName());
    _name = getName() + "_clap_name";
    setHealth(FragTrap::HP);
    setEnergy(ScavTrap::EN);
    setDamage(FragTrap::DAM);
    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name)
{
    _name = getName() + "_clap_name";
    setHealth(FragTrap::HP);
    setEnergy(ScavTrap::EN);
    setDamage(FragTrap::DAM);
    std::cout << getName() << ": " << "DiamondTrap Custom Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << getName() << ": " << "DiamondTrap Default Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &object )
{
    setName(object.getName());
    setHealth(object.getHealth());
    setEnergy(object.getEnergy());
    setDamage(object.getDamage());
    return ( *this );
}

void    DiamondTrap::attack( const std::string &target )
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "ClapTrap name: " << getName() << std::endl;
    std::cout << "Name: " << _name << std::endl;
}

void    DiamondTrap::showStats()
{
    std::cout << getName() << ": hp " << getHealth() << " en " << getEnergy() << " damage " << getDamage() << std::endl;
    return ;
}
