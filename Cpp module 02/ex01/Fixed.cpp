/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:47:20 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:47:21 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*************-- Ex00 --***************/
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
    return (this->fnumber);
}

void    Fixed::setRawBits (int const raw)
{
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

/*************-- Ex01 --***************/


Fixed::Fixed(int number)
{
    std::cout << "Int Constructor called" << std::endl;
    this->fnumber = (number << Fixed::frac);
}

Fixed::Fixed(float numberf)
{
    std::cout << "Float Constructor called" << std::endl;
    this->fnumber = roundf(numberf * (1 << Fixed::frac));
}

float   Fixed::toFloat(void) const
{
    return ((float)this->getRawBits() / (float)(1 << Fixed::frac));
}

int     Fixed::toInt (void) const
{
    return (this->getRawBits() >> Fixed::frac);
}

std::ostream& operator<<(std::ostream& out, const Fixed& num)
{
    out << num.toFloat();
    return (out);
}

