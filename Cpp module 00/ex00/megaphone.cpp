/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:21:40 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/04/20 11:21:43 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

std::string megaphone(char *str)
{
	std::string ret;

	for (int i = 0; str[i]; i++)
		ret += toupper(str[i]);
	return (ret);
}

int	main(int argc, char **argv)
{
	int		i;
	std::string	output;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 0;
		while (++i < argc)
			output += megaphone(argv[i]);
		std::cout << output << std::endl;
	}
	return (0);
}
