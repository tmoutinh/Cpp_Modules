/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:47:43 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 15:30:16 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*************-- Ex00 --***************/
Fixed::Fixed()
{
    this->fnumber = 0;
}

Fixed::~Fixed()
{
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
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->fnumber = other.getRawBits();
    return *this;
}

/*************-- Ex01 --***************/

Fixed::Fixed(int number)
{
    this->fnumber = (number << Fixed::frac);
}

Fixed::Fixed(float numberf)
{
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

/*************-- Ex02 --***************/
/*------*****- Operations -*******--------*/

bool Fixed::operator>(const Fixed& num)
{
    return (this->getRawBits() > num.getRawBits());
}

bool Fixed::operator<(const Fixed& num)
{
    return (this->getRawBits() < num.getRawBits());
}

bool Fixed::operator==(const Fixed& num)
{
    return (this->getRawBits() == num.getRawBits());
}

bool Fixed::operator!=(const Fixed& num)
{
    return (this->getRawBits() != num.getRawBits());
}

bool Fixed::operator<=(const Fixed& num)
{
    return (this->getRawBits() <= num.getRawBits());
}

bool Fixed::operator>=(const Fixed& num)
{
    return (this->getRawBits() >= num.getRawBits());
}

Fixed Fixed::operator+(const Fixed& num)
{
    Fixed res;

    res = this->toFloat() + num.toFloat();
    return (res);
}

Fixed Fixed::operator-(const Fixed& num)
{
    Fixed res;

    res = this->toFloat() - num.toFloat();
    return (res);
}

Fixed Fixed::operator*(const Fixed& num)
{
    Fixed res;

    res = this->toFloat() * num.toFloat();
    return (res);
}

Fixed Fixed::operator/(const Fixed& num)
{
    Fixed res;

    res = this->toFloat() / num.toFloat();
    return (res);
}

Fixed Fixed::operator++(void)
{
    this->fnumber = (this->getRawBits() + 1);
    return (*this);
}

Fixed Fixed::operator--(void)
{
    this->fnumber = (this->getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator++(int num)
{
    Fixed temp;

    (void)num;
    temp = *this;
    this->fnumber = (this->getRawBits() + 1);
    return (temp);
}

Fixed Fixed::operator--(int num)
{
    Fixed temp;

    (void)num;
    temp = *this;
    this->fnumber = (this->getRawBits() - 1);
    return (temp);
}
/*------*****- Functions -*******--------*/

const Fixed &Fixed::max(const Fixed& num1, const Fixed& num2)
{
    if (num1.toFloat() > num2.toFloat())
        return (num1);
    else
        return (num2);
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
    if (num1.toFloat() > num2.toFloat())
        return (num1);
    else
        return (num2);
}

const Fixed &Fixed::min(const Fixed& num1, const Fixed& num2)
{
    if (num1.toFloat() > num2.toFloat())
        return (num1);
    else
        return (num2);
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
    if (num1.toFloat() > num2.toFloat())
        return (num1);
    else
        return (num2);
}
