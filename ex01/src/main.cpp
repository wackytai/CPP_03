#include "../inc/ScavTrap.hpp"

int main(void)
{
    ScavTrap    A("A");
    ScavTrap    B(A);

    B.setName("B");
    B.attack(A);
    B.attack(A);
    B.attack(A);
    B.attack(A);
    B.attack(A);
    B.attack(A);
    return 0;
}