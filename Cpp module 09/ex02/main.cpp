/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:05:57 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/27 16:06:28 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    usage()
{
    std::cout << "./PmergeMe [positive integer sequence]" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        usage();
        return (-1);
    }
    
}