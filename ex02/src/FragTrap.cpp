#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("frag obj", 100, 100, 30)
{
    std::cout << getName() << ": " << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name, 100, 100, 30)
{
    std::cout << getName() << ": " << "FragTrap Custom Constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap &object ) : ClapTrap(object._name, object._hp, object._energy, object._damage)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << getName() << ": " << "FragTrap Destructor called" << std::endl;
}

FragTrap    &FragTrap::operator=( const FragTrap &object )
{
    setName(object._name);
    setHealth(object._hp);
    setEnergy(object._energy);
    setDamage(object._damage);
    return ( *this );
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap requests a positive high fives" << std::endl;
}

void        FragTrap::attack( const std::string &target )
{
    if (getEnergy() > 0)
    {
        std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getDamage() << " points of damage!" << std::endl;
        if (getEnergy() > 0)
            setEnergy(getEnergy() - 1);
        else
            setEnergy(0);
    }
    else if (getEnergy() <= 0)
        std::cout << "FragTrap " << getName() << ": Unable to attack. No energy points left!" << std::endl;
    return ;
}
