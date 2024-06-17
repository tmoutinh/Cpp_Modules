/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:08:15 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/17 20:20:07 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template< typename T >
void    iter(T *array, int length, void (*func)(T const &))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template< typename T >
void    print(T print)
{
    std::cout << print << std::endl;
}

#endif