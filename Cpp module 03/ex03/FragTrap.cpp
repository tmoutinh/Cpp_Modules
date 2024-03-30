#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hp = 100;
    this->ene = 100;
    this->atk = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " has been created" << std::endl;
    this->hp = 100;
    this->ene = 100;
    this->atk = 30;
}

FragTrap::FragTrap(const FragTrap& trap) : ClapTrap(trap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other)
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " has requested high fives" << std::endl;
}