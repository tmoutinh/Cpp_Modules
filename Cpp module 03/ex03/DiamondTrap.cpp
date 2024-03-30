#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->hp = 100;
    this->ene = 50;
    this->atk = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap " << name << " has been created" << std::endl;
    this->hp = 100;
    this->ene = 50;
    this->atk = 30;
	this->ClapTrap::name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap& trap) : ClapTrap(trap), ScavTrap(trap), FragTrap(trap)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	//this->name = trap.name;
}


DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
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

/*******************ACTIONS*******************/

void    DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << DiamondTrap::name << "ClapTrap name is " << ClapTrap::name << std::endl;
}
