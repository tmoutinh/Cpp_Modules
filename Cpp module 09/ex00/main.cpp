/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:10:41 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/21 13:53:06 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char**argv)
{
    BitcoinExchange exchange;
    
    if (argc != 2)
    {
        std::cout << "Usage: ./bitcoin [filename]" << std::endl;
        return 1;
    }
    try
    {
        exchange.run(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}