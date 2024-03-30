#ifndef FRAGTRAP_HPP

#define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& trap);
    virtual ~FragTrap();

    FragTrap& operator=(const FragTrap& trap);

	//! Others
	void  highFivesGuys(void);
};
#endif