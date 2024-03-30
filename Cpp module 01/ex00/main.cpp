#include "Zombie.hpp"


int main()
{
    Zombie *Zomb = newZombie("Herald");
    randomChump("Dai");
    Zomb->announce();
    delete Zomb;
    return (0);
}
