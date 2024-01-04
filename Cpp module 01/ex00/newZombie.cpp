#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie  *Zomb = new Zombie(name);

    return (Zomb);
}