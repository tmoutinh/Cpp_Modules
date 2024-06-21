/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:06:20 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/20 20:08:47 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) 
{
    _size = n;
}

Span::Span(const Span& other) 
{
    *this = other;
}

Span& Span::operator=(const Span& other) 
{
    if (this != &other) 
    {
    }
    return (*this);
}

Span::~Span() 
{
}

void    Span::addNumber(int n)
{
    if (_container.size() >= _size)
        throw Span::FullContainer();
    _container.push_back(n);
}

int    Span::shortestSpan()
{
    if (_container.size() <= 1)
        throw Span::EmptyContainer();
    std::sort(_container.begin(), _container.end());
    int minSpan = _container[1] - _container[0];
    for (std::size_t i = 1; i < _container.size(); ++i)
    {
        int Span = _container[i] - _container[i - 1];
        if (Span < minSpan)
        {
            minSpan = Span;
        }
    }
    return (minSpan);
}

int    Span::longestSpan()
{
    if (_container.size() <= 1)
        throw Span::EmptyContainer();
    std::sort(_container.begin(), _container.end());
    int maxSpan = _container[_container.size() - 1] - _container[0];
    return (maxSpan);
}
