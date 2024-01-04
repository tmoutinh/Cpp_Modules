#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "HumanA.hpp"

class HumanB{
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		~HumanB();
		HumanB(std::string name);
		void	attack();
		void	setWeapon(Weapon &type);
};

#endif