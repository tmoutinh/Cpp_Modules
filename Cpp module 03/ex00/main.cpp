/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:50:08 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:50:09 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("ClapTrap");
    ClapTrap b("ClapTrap2");

    a.attack("ClapTrap2");
    b.takeDamage(5);
    a.attack("ClapTrap2");
    b.takeDamage(5);
    b.beRepaired(5);
}