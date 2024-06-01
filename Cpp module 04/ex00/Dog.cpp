/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:53:09 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:53:10 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default const was called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog default destruc was called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy const was called" << std::endl;
    *this = other;
}

Dog  &Dog::operator=(const Dog &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "eng: Bark Bark" << std::endl;
    std::cout << "pt: AU AU" << std::endl;
}