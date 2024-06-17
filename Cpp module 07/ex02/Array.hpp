/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:22:48 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/17 20:48:39 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template< typename T >
class Array
{
    private:
        T   *_array;
        int _size;
    public:
        Array()
        {
            _array = new T[0];
            _size = 0;
        
        };
        Array(int   n)
        {
            _array = new T[n];
            _size = n;
        };
        Array(const Array& other)
        {
            _array = new T[other._size];
            _size = other._size;
            for (int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        };
        Array& operator=(const Array& other)
        {
            _array = new T[other._size];
            _size = other._size;
            for (int i = 0; i < _size; i++)
                _array[i] = other._array[i];
            return _array;
        };
        ~Array()
        {
            delete [] _array;
        };
        int size() const
        {
            return _size;
        };
        T& operator[](int index)
        {
            if (index < 0 || index >= _size)
                throw std::out_of_range("Not Valid Index \n");
            return _array[index];
        };
};

#endif