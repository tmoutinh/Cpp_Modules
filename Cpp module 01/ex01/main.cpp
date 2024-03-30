#include "Zombie.hpp"

int main()
{
    int z = 3;
    Zombie *horde;

    horde = zombieHorde(z, "Herold");
    for(int i = 0; i < z; ++i)
        horde[i].announce();
    delete [] horde;
    return (0);
}
