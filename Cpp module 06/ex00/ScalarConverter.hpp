/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 23:04:46 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/17 19:38:41 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>

enum    Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

class ScalarConverter 
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        
    public:
        static bool    is_char(std::string input);
        static bool    is_int(std::string input);
        static bool    is_float(std::string input);
        static bool    is_double(std::string input);
        static bool    is_pseudo(std::string input);
        static void    convert(std::string input);
        static void    convertChar(char c, std::string input);
        static void    convertInt(int c, std::string input);
        static void    convertFloat(float c, std::string input);
        static void    convertDouble(double c, std::string input);
        static void    convertNumber(std::string input, long double number);
        static void    convertPseudo(std::string input);
        static bool    overflow(std::string input, Type type);
        static bool  decimalSize(std::string input);
        class ImpossibleConversion : public std::exception
	    {
	    	public:
		    	virtual const char *what() const throw() { return ("Not Valid conversion.\n");}
	    };
};



#endif