#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    return ;
}

Zombie::~Zombie()
{
    return ;
}

void    Zombie::announce()
{
    std::cout << this->_name;
    std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
