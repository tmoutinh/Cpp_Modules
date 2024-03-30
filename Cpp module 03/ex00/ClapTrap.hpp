#ifndef _CLAP_TRAP_HPP
# define _CLAP_TRAP_HPP

#include <iostream>


class ClapTrap
{
private:
	std::string	name;
	int	hp;
	int	ene;
	int	atk;
public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(const ClapTrap &other);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};





#endif