/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:55:27 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:55:28 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default const was called" << std::endl;
    this->type = "Dog";
    brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog default destruc was called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy const was called" << std::endl;
    *this = other;
    delete this->brain;
    this->brain = new Brain(*(other.brain));
}

Dog  &Dog::operator=(const Dog &other)
{
    if (this == &other)
        return (*this);
    delete this->brain;
    this->type = other.type;
    this->brain = new Brain(*(other.brain));
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "eng: Bark Bark" << std::endl;
    std::cout << "pt: AU AU" << std::endl;
}

Brain *Dog::getBrain(void) const
{
    return (this->brain);
}