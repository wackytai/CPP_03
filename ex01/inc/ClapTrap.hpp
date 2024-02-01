#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <cstring>

class ClapTrap
{
    protected:
        std::string     _name;
        unsigned int    _hp;
        unsigned int    _energy;
        unsigned int    _damage;

    public:
        ClapTrap();
        ClapTrap( std::string name, unsigned int hp, unsigned int e, unsigned int dam );
        ClapTrap( const ClapTrap& object );
        ClapTrap( std::string name );
        ~ClapTrap();
        void            attack( const std::string& target );
        void            takeDamage( unsigned int amount );
        void            beRepaired( unsigned int amount );
        ClapTrap&       operator=( const ClapTrap& object );
        std::string     getName() const;
        unsigned int    getHealth() const;
        unsigned int    getEnergy() const;
        unsigned int    getDamage() const;
        void            setName( std::string name );
        void            setHealth( unsigned int amount );
        void            setEnergy( unsigned int amount );
        void            setDamage( unsigned int amount );
};

#endif