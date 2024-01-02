#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("", FragTrap::getHealth(), ScavTrap::getEnergy(), FragTrap::getDamage()), _name("_clap_name")
{
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &object )
{
    *this = object;
    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : _name(name + "_clap_trap"), ClapTrap(name, FragTrap::getHealth(), ScavTrap::getEnergy(), FragTrap::getDamage())
{
    std::cout << "DiamondTrap Custom Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() override
{
    std::cout << "DiamondTrap Default Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &object )
{
    setName(object.getName());
    setHealth(object.getHealth());
    setEnergy(object.getEnergy());
    setDamage(object.getDamage());
    return ( *this );
}

void    DiamondTrap::whoAmI()
{
    std::cout << "ClapTrap name: " << getName() << std::endl;
    std::cout << "Name: " << _name << std::endl;
}
