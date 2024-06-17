/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:00:18 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/17 20:04:12 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template< typename T >
void    swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
};

template< typename T >
T    min(T &a, T &b)
{
    if (a < b)
        return (a);
    return (b);
};

template< typename T >
T    max(T &a, T &b)
{
    if (a > b)
        return (a);
    return (b);
};


#endif