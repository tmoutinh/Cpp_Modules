/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:52:03 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:52:04 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
