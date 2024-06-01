/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:48:14 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:48:15 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float num1, const float num2) : x(num1), y(num2)
{
}

Point::~Point()
{
}

Point::Point(const Point& other)
{
    *this = other;
}

Point &Point::operator=(const Point& other)
{
}
