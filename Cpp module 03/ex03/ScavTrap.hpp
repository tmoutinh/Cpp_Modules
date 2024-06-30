/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:52:23 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:52:25 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& trap);
    virtual ~ScavTrap();

    ScavTrap& operator=(const ScavTrap& trap);

	//! Others
	void attack(const std::string &target);		
	void guardGate(void);
};

#endif
