/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:15:56 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/21 15:36:36 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <limits>

class BitcoinExchange 
{
    private:
        std::map<std::string, float> _data_base;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        
        void    run(const char *filename);
        bool    ExchangeRates();
        bool    ExchangeCalculator(const char *filename);
        void    input_verif(std::string date, double amount);
        std::string find_closest(std::string date);

        class InvalidExchange : public std::exception
        {
            public:
                virtual const char *what() const throw() {return "Invalid Exchange File\n";}
        };
        class WrongFormat : public std::exception
        {
            public:
                virtual const char *what() const throw() {return "Wrong Format In File\n";}
        };
};

#endif