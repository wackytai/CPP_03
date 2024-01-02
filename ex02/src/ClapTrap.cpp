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
    std::cout << "Custom Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Default Destructor called" << std::endl;
}

void        ClapTrap::attack( const std::string& target )
{
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    setEnergy(-1);
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
        std::cout << "No energy points left!" << std::endl;
    else if (target.getHealth() <= 0)
        std::cout << "Target has no HP!" << std::endl;
    return ;
}

void        ClapTrap::takeDamage( unsigned int amount )
{
    setHealth(amount * -1);
    std::cout << _name << " attacked, losing " << _damage << " points of hp!" << std::endl;
    return ;
}

void        ClapTrap::beRepaired( unsigned int amount )
{
    if (_energy > 0)
    {
        setHealth(amount);
        std::cout <<  _name << " repaired hp by " << amount << std::endl;
        setEnergy(-1);
    }
    std::cout << "No energy points left!" << std::endl;
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

std::string     ClapTrap::getName()
{
    return ( _name );
}

unsigned int    ClapTrap::getHealth()
{
    return ( _hp );
}

unsigned int    ClapTrap::getEnergy()
{
    return ( _energy );
}

unsigned int    ClapTrap::getDamage()
{
    return ( _damage );
}

void            ClapTrap::setName( std::string name )
{
    _name = name;
}

void            ClapTrap::setHealth( unsigned int amount )
{
    _hp += amount;
}

void            ClapTrap::setEnergy( unsigned int amount )
{
    _energy += amount;
}

void            ClapTrap::setDamage( unsigned int amount )
{
    _damage += amount;
}
