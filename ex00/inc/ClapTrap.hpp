#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <cstring>

class ClapTrap
{
    private:
        std::string     _name;
        unsigned int    _hp;
        unsigned int    _energy;
        unsigned int    _damage;

    public:
        ClapTrap();
        ClapTrap( const ClapTrap& object );
        ClapTrap( std::string name );
        ~ClapTrap();
        void            attack( const std::string& target );
        void            attack( ClapTrap& target );
        void            takeDamage( unsigned int amount );
        void            beRepaired( unsigned int amount );
        ClapTrap&       operator=( const ClapTrap& object );
        std::string     getName();
        unsigned int    getHealth();
        unsigned int    getEnergy();
        unsigned int    getDamage();
        void            setName( std::string name );
        void            setHealth( unsigned int amount );
        void            setEnergy( unsigned int amount );
        void            setDamage( unsigned int amount );
};

#endif