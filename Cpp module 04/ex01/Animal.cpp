/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:53:49 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:53:50 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default const was called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal default destruc was called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy const was called" << std::endl;
    *this = other;
}

Animal  &Animal::operator=(const Animal &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void    Animal::makeSound() const
{
    std::cout << "*** ANIMAL SOUND ***" << std::endl;
}

std::string    Animal::getType() const
{
    return (this->type);
}