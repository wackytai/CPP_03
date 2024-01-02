#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30)
{
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap Custom Constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap &object )
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = object;
}

FragTrap::~FragTrap() override
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap    &FragTrap::operator=( const FragTrap &object )
{
    setName(object.getName());
    setHealth(object.getHealth());
    setEnergy(object.getEnergy());
    setDamage(object.getDamage());
    return ( *this );
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap requests a positive high fives" << std::endl;
}

void        FragTrap::attack( FragTrap &target ) override
{
    if (getEnergy() > 0 && target.getHealth() > 0)
    {
        attack(target.getName());
        target.takeDamage(getDamage());
    }
    else if (getEnergy() <= 0)
        std::cout << "No energy points left!" << std::endl;
    else if (target.getHealth() <= 0)
        std::cout << "Target has no HP!" << std::endl;
    return ;
}

void        FragTrap::attack( const std::string &target ) override
{
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    setEnergy(-1);
    return ;
}
