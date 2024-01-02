#include "../inc/ClapTrap.hpp"

int main(void)
{
    ClapTrap    A("A");
    ClapTrap    B(A);

    B.setName("B");
    A.setDamage(2);
    A.attack(B);
    A.setDamage(4);
    A.attack(B);
    A.attack(B);
    A.attack(B);
    return 0;
}