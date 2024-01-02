#include "../inc/ClapTrap.hpp"

int main(void)
{
    ClapTrap    A("A");
    ClapTrap    B(A);

    B.setName("B");
    A.attack(B);
    return 0;
}