/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:29:12 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/27 16:00:13 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() 
{
}

bool    is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return (true);
    return (false);
}

bool    is_valid(char c)
{
    if (std::isdigit(c) || is_operator(c))
        return (true);
    return (false);
}  

void    RPN::calculate(char c)
{
    int first;
    int second;

    second = this->_stack.top();
	this->_stack.pop();
	first = this->_stack.top();
	this->_stack.pop();
	
	if (c == '+')
		this->_stack.push(first + second);
	else if (c == '-')
		this->_stack.push(first - second);
	else if (c == '*')
		this->_stack.push(first * second);
	else
		this->_stack.push(first / second);
}

void    RPN::solve(std::string str)
{
    char				symbol;	
	std::stringstream	stream(str);

    while (stream >> symbol)
    {
        if (!is_valid(symbol))
        {
            ERROR_INV_SYMBOL(symbol);
            return ;
        }
        if (is_operator(symbol) && this->_stack.size() < 2)
		{
            ERROR_FEW_ARGS(symbol);
            return ;
        }
        if (!is_operator(symbol))
            this->_stack.push(symbol - '0');
        else
            calculate(symbol);
    }
    if (this->_stack.size() > 1)
        ERROR_LEFTOVER;
    else
        std::cout << this->_stack.top() << std::endl;
}


RPN::RPN(const RPN& other) 
{
    if (this != &other) 
    {
        this->_stack = other._stack;
    }
}

RPN& RPN::operator=(const RPN& other) 
{
    if (this != &other) 
    {
        this->_stack = other._stack;
    }
    return (*this);
}

RPN::~RPN() 
{
}

