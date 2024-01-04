#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	_weapon = NULL;
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their ";
	if (_weapon != NULL)
		std::cout << this->_weapon->getType() << std::endl;
	else
		std::cout << "hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &type)
{
	this->_weapon = &type;
}