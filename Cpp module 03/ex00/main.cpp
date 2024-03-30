#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("ClapTrap");
    ClapTrap b("ClapTrap2");

    a.attack("ClapTrap2");
    b.takeDamage(5);
    a.attack("ClapTrap2");
    b.takeDamage(5);
    b.beRepaired(5);
}