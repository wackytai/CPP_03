#include "../inc/ScavTrap.hpp"

Scavtrap::ScavTrap() : ClapTrap("", 100, 50, 20)
{
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

Scavtrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap Custom Constructor called" << std::endl;
}

Scavtrap::ScavTrap( const ScavTrap &object )
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = object;
}

Scavtrap::~ScavTrap()
{
    std::cout << "ScavTrap Default Destructor called" << std::endl;
}

ScavTrap   &ScavTrap::operator=( const ScavTrap &object )
{
    setName(object.getName());
    setHealth(object.getHealth());
    setEnergy(object.getEnergy());
    setDamage(object.getDamage());
    return  ( *this );
}

void        ScavTrap::attack( const std::string& target )
{
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    setEnergy(-1);
    return ;
}

void        ScavTrap::attack( ScavTrap& target )
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

void    ScavTrap::guardGate()
{
    if (!_isGuarding)
    {
        _isGuarding = true;
        std::cout << getName() << " Gate keeper mode active!" << std::endl;
    }
    else
        std::cout << getName() << " Gate keeper mode already active!" << std::endl;
}
