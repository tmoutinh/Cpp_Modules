/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:26:05 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/27 15:55:30 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

# define RED	"\033[1;31m"
# define RESET	"\033[0m"

# define ERROR(str)				std::cout << RED << str << RESET "\n"
# define ERROR_INV_SYMBOL(x)	ERROR("ERROR: unknown operation '" << x << "'")
# define ERROR_FEW_ARGS(x)		ERROR("ERROR: not enough args in stack to perform '" << x << "'")
# define ERROR_LEFTOVER			ERROR("ERROR: not all numbers were used")
# define ERROR_USAGE			ERROR("ERROR: ./RPN expression")

class RPN 
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        void    solve(std::string str);
        void    calculate(char c);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
};


#endif