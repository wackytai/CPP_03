#include "../inc/ClapTrap.hpp"

const int ClapTrap::HIT_POINTS = 10;
const int ClapTrap::ENERGY_POINTS = 10;
const int ClapTrap::ATTACK_DAMAGE = 0;

ClapTrap::ClapTrap() : _name("asset"), _hp(ClapTrap::HIT_POINTS), _energy(ClapTrap::ENERGY_POINTS), _damage(ClapTrap::ATTACK_DAMAGE)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& object )
{
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = object;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _energy(10), _damage(0)
{
    std::cout << name << ": " << "ClapTrap Custom Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << getName() << ": " << "ClapTrap Default Destructor called" << std::endl;
}

void        ClapTrap::attack( const std::string& target )
{
        if (getEnergy() > 0)
    {
        std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getDamage() << " points of damage!" << std::endl;
        if (getEnergy() > 0)
            setEnergy(getEnergy() - 1);
        else
            setEnergy(0);
    }
    else if (getEnergy() <= 0)
        std::cout << "Unable to attack. No energy points left!" << std::endl;
    return ;
}

void        ClapTrap::takeDamage( unsigned int amount )
{
    if (getHealth() == 0)
    {
        std::cout << "ClapTrap " << getName() << "has no HP left to take damage! " << std::endl;
        return ;
    }
    if (amount < getHealth())
        setHealth(getHealth() - amount);
    else
        setHealth(0);
    std::cout << "ClapTrap " << getName() << " attacked, losing " << amount << " points of hp!" << std::endl;
    return ;
}

void        ClapTrap::beRepaired( unsigned int amount )
{
    if (_energy > 0)
    {
        setHealth(getHealth() + amount);
        std::cout << "ClapTrap " << getName() << " repaired hp by " << amount << std::endl;
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
