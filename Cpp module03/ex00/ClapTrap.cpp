#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
}

ClapTrap::~ClapTrap()
{
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = (&other)->name;
		this->hp = (&other)->hp;
		this->ene = (&other)->ene;
		this->atk = (&other)->atk;
	}
	return *this;
}


/***************-- Action Member Functions --***************/

void	attack(const std::string& target)
{

}

void	takeDamage(unsigned int amount)
{

}

void	beRepaired(unsigned int amount)
{

}