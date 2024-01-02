#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
    private:
        bool    _isGuarding = false;
    public:
        ScavTrap();
        ScavTrap( std::string name );
        ScavTrap( const ScavTrap &object );
        ~ScavTrap();
        ScavTrap    &operator=( const ScavTrap &object );
        void        attack( const std::string& target );
        void        attack( ScavTrap& target );
        void        guardGate();
};

#endif