/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:13:12 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/17 20:20:26 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main(void)
{
    int tab[] = { 0, 1, 2, 3, 4 };
    ::iter(tab, 5, print);

    std::string tab2[] = { "La", "batata", "está quente" };
    ::iter(tab2, 3, print);

    std::string tab3[] = { "L", "a", "Batata" };
    ::iter(tab3, 3, print);
    
    return (0);
}