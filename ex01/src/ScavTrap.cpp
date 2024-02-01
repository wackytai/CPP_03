#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("scav obj", 100, 50, 20)
{
    _isGuarding = false;
    std::cout << getName() << ": " << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    _isGuarding = false;
    std::cout << getName() << ": " << "ScavTrap Custom Constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &object ) : ClapTrap(object._name, object._hp, object._energy, object._damage)
{
    _isGuarding = object._isGuarding;
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << getName() << ": " << "ScavTrap Default Destructor called" << std::endl;
}

void    ScavTrap::attack( const std::string& target )
{
    if (getEnergy() > 0)
    {
        std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getDamage() << " points of damage!" << std::endl;
        if (getEnergy() > 0)
            setEnergy(getEnergy() - 1);
        else
            setEnergy(0);
    }
    else if (getEnergy() <= 0)
        std::cout << "ScavTrap " << getName() << ": Unable to attack. No energy points left!" << std::endl;
    return ;
}

ScavTrap   &ScavTrap::operator=( const ScavTrap &object )
{
    setName(object._name);
    setHealth(object._hp);
    setEnergy(object._energy);
    setDamage(object._damage);
    _isGuarding = object._isGuarding;
    return  ( *this );
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
