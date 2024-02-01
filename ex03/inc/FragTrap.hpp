#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    protected:
        static const int    HP;
        static const int    EN;
        static const int    DAM;

    public:
        FragTrap();
        FragTrap( std::string name );
        FragTrap( const FragTrap &object );
        ~FragTrap();
        FragTrap    &operator=( const FragTrap &object );
        void        highFivesGuys(void);
        void        attack( const std::string &target );
};

#endif