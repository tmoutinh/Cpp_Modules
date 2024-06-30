/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:52:07 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:52:08 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void usage(void)
{
        std::cout << "Usage: ./ex03 trap_name" << std::endl;
}

int main(int argc, char **argv)
{
        if (argc < 2)
        {
                usage();
                return (-1);
        }
        DiamondTrap t1;
        DiamondTrap t2(argv[1]);
        DiamondTrap t3(t2);

        std::cout << "\n-------- Testing --------\n" << std::endl;
        t3.attack("something");
	t3.takeDamage(9);
	t3.beRepaired(5);
	t3.guardGate();
	t3.highFivesGuys();
	t3.whoAmI();
	t3.takeDamage(100);
	t3.beRepaired(50);
        return (0);
}