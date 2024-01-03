#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hp(10), _energy(10), _damage(0)
{
    std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& object )
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = object;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _energy(10), _damage(0)
{
    std::cout << name << ": " << "Custom Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << getName() << ": " << "Default Destructor called" << std::endl;
}

void        ClapTrap::attack( const std::string& target )
{
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    setEnergy(getEnergy() - 1);
    return ;
}

void        ClapTrap::attack( ClapTrap& target )
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

void        ClapTrap::takeDamage( unsigned int amount )
{
    setHealth(getHealth() - amount);
    std::cout << "ClapTrap " << _name << " attacked, losing " << amount << " points of hp!" << std::endl;
    return ;
}

void        ClapTrap::beRepaired( unsigned int amount )
{
    if (_energy > 0)
    {
        setHealth(getHealth() + amount);
        std::cout << "ClapTrap " << _name << " repaired hp by " << amount << std::endl;
        setEnergy(getEnergy() - 1);
    }
    else
        std::cout << "Unable to repair. No energy points left!" << std::endl;
    return ;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& object )
{
    std::cout << "Copy assignment operator called" << std::endl;
    _name = object.getName();
    _hp = object.getHealth();
    _energy = object.getEnergy();
    _damage = object.getDamage();
    return ( *this );
}

std::string     ClapTrap::getName() const
{
    return ( _name );
}

unsigned int    ClapTrap::getHealth() const
{
    return ( _hp );
}

unsigned int    ClapTrap::getEnergy() const
{
    return ( _energy );
}

unsigned int    ClapTrap::getDamage() const
{
    return ( _damage );
}

void            ClapTrap::setName( std::string name )
{
    _name = name;
}

void            ClapTrap::setHealth( unsigned int amount )
{
    if (amount >= 0)
        _hp = amount;
    else
        _hp = 0;
}

void            ClapTrap::setEnergy( unsigned int amount )
{
    if (amount >= 0)
        _energy = amount;
    else
        _energy = 0;
}

void            ClapTrap::setDamage( unsigned int amount )
{
    _damage = amount;
}
