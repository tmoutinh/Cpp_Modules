/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:52:19 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:52:20 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hp = 100;
    this->ene = 50;
    this->atk = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " has been created" << std::endl;
    this->hp = 100;
    this->ene = 50;
    this->atk = 20;
}

ScavTrap::ScavTrap(const ScavTrap& trap) : ClapTrap(trap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}


ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
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

void	ScavTrap::attack(const std::string& target)
{
	if(this->ene > 0 && this->hp > 0)
	{
		this->ene -= 1;
		std::cout << "ScavTrap " << this->name;
		std::cout << " Attacks " << target;
		std::cout << ", dealing " << this->atk << std::endl;
	}
	else
	{
		if (this->ene == 0)
		{
			std::cout << "ScavTrap " << this->name;
			std::cout << " is out of energy" << std::endl;
		}
		else
		{
			std::cout << "ScavTrap " << this->name;
			std::cout << " has no hit points" << std::endl;
		}
	}
}

void ScavTrap::guardGate(void)
{
	std::cout << "\n\tScavTrap " << this->name << " is in Gate Keeper mode\n" << std::endl;
}