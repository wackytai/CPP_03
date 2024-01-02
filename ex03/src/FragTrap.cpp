#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    setHealth(100);
    setEnergy(100);
    setDamage(30);
    std::cout << getName() << ": " << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    setHealth(100);
    setEnergy(100);
    setDamage(30);
    std::cout << getName() << ": " << "FragTrap Custom Constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap &object ) : ClapTrap()
{
    setName(object.getName());
    setHealth(object.getHealth());
    setEnergy(object.getEnergy());
    setDamage(object.getDamage());
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << getName() << ": " << "FragTrap Destructor called" << std::endl;
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

void        FragTrap::attack( FragTrap &target )
{
    if (getEnergy() > 0 && target.getHealth() > 0)
    {
        attack(target.getName());
        target.takeDamage(getDamage());
    }
    else if (getEnergy() <= 0)
        std::cout << "Unable to attack. No energy points left!" << std::endl;
    else if (target.getHealth() <= 0)
        std::cout << "Unable to attack. Target has no HP!" << std::endl;
    return ;
}

void        FragTrap::attack( const std::string &target )
{
    std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getDamage() << " points of damage!" << std::endl;
    setEnergy(-1);
    return ;
}
