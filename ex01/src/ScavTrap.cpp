#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    setHealth(100);
    setEnergy(50);
    setDamage(20);
    _isGuarding = false;
    std::cout << getName() << ": " << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    setHealth(100);
    setEnergy(50);
    setDamage(20);
    _isGuarding = false;
    std::cout << getName() << ": " << "ScavTrap Custom Constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &object ) : ClapTrap()
{
    setName(object.getName());
    setHealth(object.getHealth());
    setEnergy(object.getEnergy());
    setDamage(object.getDamage());
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << getName() << ": " << "ScavTrap Default Destructor called" << std::endl;
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
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getDamage() << " points of damage!" << std::endl;
    setEnergy(getEnergy() - 1);
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
