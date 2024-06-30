/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:12:58 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/27 16:13:54 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 

PmergeMe::PmergeMe() 
{
}

PmergeMe::PmergeMe(const PmergeMe& other) 
{
    if (this != &other) 
    {
    }
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{
    if (this != &other) 
    {
    }
    return (*this);
}

PmergeMe::~PmergeMe() 
{
}

bool     PmergeMe::parse(char *argv[])
{
    std::string total;
    std::stringstream   stream;
    
    total = std::string(argv[0]);	
	for (int i = 1; argv[i]; i++)
		total += " " + std::string(argv[i]);	
	stream << total;
}

void    PmergeMe::pair_division()
{

}
