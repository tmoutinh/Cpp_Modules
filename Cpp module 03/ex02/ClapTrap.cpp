/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:50:56 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:50:57 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor was called" << std::endl;
	this->name = "";
	this->hp = 10;
	this->ene = 10;
	this->atk = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap " << name << " has been created" << std::endl;
	this->name = name;
	this->hp = 10;
	this->ene = 10;
	this->atk = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor was called" << std::endl;
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

void	ClapTrap::attack(const std::string& target)
{
	if(this->ene > 0 && this->hp > 0)
	{
		this->ene -= 1;
		std::cout << "ClapTrap " << this->name;
		std::cout << " Attacks " << target;
		std::cout << ", dealing " << this->atk << std::endl;
	}
	else
	{
		if (this->ene == 0)
		{
			std::cout << "ClapTrap " << this->name;
			std::cout << " is out of energy" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->name;
			std::cout << " has no hit points" << std::endl;
		}
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if(this->ene > 0 && this->hp > 0)
	{
		this->hp -= amount;
		std::cout << "ClapTrap " << this->name;
		std::cout << " Takes " << amount << " damage" << std::endl;
	}
	else
	{
		if (this->ene == 0)
		{
			std::cout << "ClapTrap " << this->name;
			std::cout << " is out of energy" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->name;
			std::cout << " has no hit points" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
		if(this->ene > 0 && this->hp > 0)
	{
		this->ene -= 1;
		std::cout << "ClapTrap " << this->name;
		std::cout << " Repairs " << amount << " hit points" << std::endl;
	}
	else
	{
		if (this->ene == 0)
		{
			std::cout << "ClapTrap " << this->name;
			std::cout << " is out of energy" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->name;
			std::cout << " has no hit points" << std::endl;
		}
	}
}
