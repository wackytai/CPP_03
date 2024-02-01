#include "../inc/FragTrap.hpp"

const int   FragTrap::HP = 100;
const int   FragTrap::EN = 100;
const int   FragTrap::DAM = 30;

FragTrap::FragTrap() : ClapTrap("frag obj", FragTrap::HP, FragTrap::EN, FragTrap::DAM)
{
    std::cout << getName() << ": " << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name, FragTrap::HP, FragTrap::EN, FragTrap::DAM)
{
    std::cout << getName() << ": " << "FragTrap Custom Constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap &object ) : ClapTrap(object._name, object._hp, object._energy, object._damage)
{
    std::cout << getName() << ": " << "FragTrap Copy Constructor called" << std::endl;
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
