#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class   Zombie
{
public:
    Zombie();
    ~Zombie();
    void    announce();
    void    set_name(std::string name);
private:
    std::string _name;
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);


#endif