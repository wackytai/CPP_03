#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : virtual public ClapTrap
{
    protected:
        bool    _isGuarding;
        static const int    HP;
        static const int    EN;
        static const int    DAM;

    public:
        ScavTrap();
        ScavTrap( std::string name );
        ScavTrap( const ScavTrap &object );
        ~ScavTrap();
        ScavTrap    &operator=( const ScavTrap &object );
        void        attack( const std::string& target );
        void        guardGate();
};

#endif