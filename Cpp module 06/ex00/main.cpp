/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:32:25 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/17 19:32:32 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::string str = argv[1];
		try
		{
			ScalarConverter::convert(str);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cerr << "Invalid number of arguments." << std::endl;
		return (1);
	}
	return (0);
}