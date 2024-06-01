/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:54:06 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:54:07 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default const was called" << std::endl;
    this->type = "Cat";
    brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat default destruc was called" << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy const was called" << std::endl;
    *this = other;
    delete this->brain;
    this->brain = new Brain(*(other.brain));
}

Cat  &Cat::operator=(const Cat &other)
{
    if (this == &other)
        return (*this);
    delete this->brain;
    this->type = other.type;
    this->brain = new Brain(*(other.brain));
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "eng: Meow Meow " << std::endl;
    std::cout << "pt: Miau Miau" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}