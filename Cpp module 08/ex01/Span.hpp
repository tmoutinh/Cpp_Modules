/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:00:40 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/17 23:20:07 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span 
{
    private:
        std::vector<int>    _container;
        unsigned int        _size;
    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void    addNumber(int n);
        int    shortestSpan();
        int    longestSpan();
        class FullContainer : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Container is full.";
                }
        };
        class EmptyContainer : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Unable to perform action: Insufficient numbers.";
                }
        };
};


#endif