#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie *Zomb;

    Zomb->set_name(name);
    Zomb->announce();
}