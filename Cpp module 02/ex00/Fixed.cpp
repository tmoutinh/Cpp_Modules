/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:47:02 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:47:03 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default Constructor called" << std::endl;
    this->fnumber = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fnumber);
}

void    Fixed::setRawBits (int const raw)
{
    std::cout << "setRawBites member function called" << std::endl;
    this->fnumber = raw;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &other)
        this->fnumber = other.getRawBits();
    return *this;
}
