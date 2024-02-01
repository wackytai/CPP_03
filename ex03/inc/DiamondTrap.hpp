#ifndef DIAMOND_HPP
# define DIAMOND_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap( const DiamondTrap &object );
        DiamondTrap( std::string name );
        ~DiamondTrap() ;
        DiamondTrap &operator=( const DiamondTrap &object );
        void    attack( const std::string &target );
        void    whoAmI();
        void    showStats();
};

#endif