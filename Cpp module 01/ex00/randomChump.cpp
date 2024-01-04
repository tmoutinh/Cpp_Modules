#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie Zomb = Zombie(name);

    Zomb.announce();
}