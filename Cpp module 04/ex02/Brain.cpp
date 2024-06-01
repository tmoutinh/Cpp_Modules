/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:55:09 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:55:10 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default const was called" << std::endl;
    const std::string ideas[] = 
	{
		"I am hungry",
		"I want to play",
		"I need to pee",
		"I want pets!",
		"RAWRRRR",
		"..."
	};

	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas[rand() % 6];
}

Brain::~Brain()
{
    std::cout << "Brain default destruc was called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy const was called" << std::endl;
    *this = other;
    for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain  &Brain::operator=(const Brain &other)
{
    if (this == &other)
        return (*this);
    for(int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return (*this);
}