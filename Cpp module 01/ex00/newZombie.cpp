#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie  *Zomb = new Zombie;

    Zomb->set_name(name);
    Zomb->announce();
    return (Zomb);
}