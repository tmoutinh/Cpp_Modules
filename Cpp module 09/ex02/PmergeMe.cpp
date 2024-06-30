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
    int                 number;
    std::string         total;
    std::vector<int>    vec;
    std::stringstream   stream;

    total = std::string(argv[0]);	
	for (int i = 1; argv[i]; i++)
		total += " " + std::string(argv[i]);	
	stream << total;
    while (!stream.eof())
    {
        if (!stream >> number)
            return (false);
        if (number < 0)
            return (false);
        if (std::find(vec.begin(), vec.end(), number) != vec.end())
            return (false);
        vec.push_back(number);
    }
}

void    PmergeMe::pair_split()
{
    
}