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
bool    ScalarConverter::is_char(std::string input)
{
	return (input.size() <= 1 && std::isprint(input[0])
	 && !std::isdigit(input[0]));
}

bool    ScalarConverter::is_int(std::string input)
{
	size_t sign = input.find('-');
	size_t index = 0;

	if (overflow(input, INT))
		return (false);
	if (sign != 0)
		sign = input.find('+');
	if (sign != std::string::npos && sign != 0)
		return (false);
	if (sign == 0)
		index = 1;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
			return (false);
	}
	return (sign == 0 ? input.size() > 1 : input.size() > 0);
}

bool    ScalarConverter::is_float(std::string input)
{
	size_t index = 0;
	size_t f = input.find('f');
	size_t dot = input.find('.');
	size_t sign = input.find('-');

	if (dot == std::string::npos || f == std::string::npos)
		return (false);
	if (sign != 0)
		sign = input.find('+');
	if (sign != std::string::npos)
		index = 1;

	std::string decimalPart = input.substr(index, dot - index);
	std::string fractionalPart = input.substr(dot + 1, f - dot - 1);

	if (fractionalPart.find('.') != std::string::npos)
		return (false);
	return (decimalPart.size() > 0 && fractionalPart.size() > 0);
}

bool    ScalarConverter::is_double(std::string input)
{
	size_t index = 0;
	size_t dot = input.find('.');
	size_t sign = input.find('-');

	if (dot == std::string::npos)
		return (false);
	if (sign != 0)
		sign = input.find('+');
	if (sign != std::string::npos)
		index = 1;

	std::string decimalPart = input.substr(index, dot - index);
	std::string fractionalPart = input.substr(dot + 1, std::string::npos);

	if (fractionalPart.find('.') != std::string::npos)
		return (false);
	return (decimalPart.size() > 0 && fractionalPart.size() > 0);

}

bool    ScalarConverter::is_pseudo(std::string input)
{
	return (input == "-inff" || input == "+inff" || input == "inf" || input == "inff"
		|| input == "-inf" || input == "+inf" || input == "nan");
}

bool    ScalarConverter::overflow(std::string input, Type type)
{
	long double num;

	num = std::strtod(input.c_str(), NULL);
	switch (type) 
	{
		case (CHAR):
			return (num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min());
		case (INT):
			return (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min());
		case (FLOAT):
			return (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min());
		case (DOUBLE):
			return (num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::min());
	}
}

void    ScalarConverter::convertChar(char c, std::string input)
{
	if (overflow(input, CHAR))
	{
		std::cout << "Char : Overflowed" << std::endl;
		return ;
	}
	if (std::isprint(c))
		std::cout << "Char : " << c << std::endl;
	else 
		std::cout << "Char : Cannot be displayed" << std::endl;
}

void    ScalarConverter::convertInt(int c, std::string input)
{
	if (overflow(input, INT))
	{
		std::cout << "Int : Overflowed" << std::endl;
		return ;
	}
	std::cout << "Int : " << c << std::endl;
}

void    ScalarConverter::convertFloat(float c, std::string input)
{
	if (overflow(input, FLOAT))
	{
		std::cout << "Float : Overflowed" << std::endl;
		return ;
	}
	if (!decimalSize(input))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "Float : " << c << "f" << std::endl;
}

void    ScalarConverter::convertDouble(double c, std::string input)
{
	if (overflow(input, DOUBLE))
	{
		std::cout << "Double : Overflowed" << std::endl;
		return ;
	}
	std::cout << "Double : " << c << std::endl;
}

bool	ScalarConverter::decimalSize(std::string input)
{
	size_t f = input.find('f');
	size_t dot = input.find('.');

	std::string fractionalPart = input.substr(dot + 1, f - dot - 1);
	if (dot == std::string::npos || fractionalPart.size() == 1)
		return (false);
	return (fractionalPart.size());
}

void    ScalarConverter::convertNumber(std::string input, long double number)
{
	convertChar((number), input);
	convertInt(static_cast<int>(number), input);
	convertFloat(static_cast<float>(number), input);
	convertDouble(static_cast<double>(number), input);
}

void    ScalarConverter::convertPseudo(std::string input)
{
	std::cout << "Char : Impossible\nInt : Impossible" << std::endl;
	size_t sign = input.find('-');

	if (input.find("nan") != std::string::npos)
	{
		std::cout << "Float : Impossible" << std::endl;
		std::cout << "Double : " << input.c_str() << std::endl;
		return ;
	}
	if (input.find("inf") != std::string::npos)
	{
		if (sign != 0)
		{
			std::cout << "Float : Inff" << std::endl;
			std::cout << "Double : Inf" << std::endl;
		}
		else
		{
			std::cout << "Float : -Inff" << std::endl;
			std::cout << "Double : -Inf" << std::endl;
		}
	}
}

void    ScalarConverter::convert(std::string input)
{
	if (is_char(input))
		convertNumber(input, input[0]);
	else if (is_int(input))
		convertNumber(input, std::atoi(input.c_str()));
	else if (is_float(input))
		convertNumber(input, std::strtof(input.c_str(), NULL));
	else if (is_double(input))
		convertNumber(input, std::strtod(input.c_str(), NULL));
	else if (is_pseudo(input))
		convertPseudo(input);
	else
	{
		std::cout << "-------------- " << input.c_str();
		std::cout << " is invalid type --------------" << std::endl;
	}
}