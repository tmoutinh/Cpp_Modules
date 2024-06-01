/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:53:00 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:53:01 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default const was called" << std::endl;
    this->type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat default destruc was called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy const was called" << std::endl;
    *this = other;
}

Cat  &Cat::operator=(const Cat &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "eng: Meow Meow " << std::endl;
    std::cout << "pt: Miau Miau" << std::endl;
}