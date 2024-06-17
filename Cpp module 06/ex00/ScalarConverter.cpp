/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 23:05:37 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/17 19:44:21 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>

/*-----------------------------------  Canonical  -----------------------------------*/

ScalarConverter::ScalarConverter() 
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
    if (this != &other) 
    {
    }
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{
    if (this != &other) 
    {
    }
    return (*this);
}

ScalarConverter::~ScalarConverter() 
{
}

/*-----------------------------------  Exercise  -----------------------------------*/

void    ScalarConverter::convert(std::string input)
{
    try
    {
        doconversion(input, )
    }
    catch(const std::exception& e)
    {
        ScalarConverter::ImpossibleConversion();
    }
}