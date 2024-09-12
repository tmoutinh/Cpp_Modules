/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:43:11 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/09/12 18:43:12 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() 
{
}

Serializer::Serializer(const Serializer& other) 
{
    if (this != &other) 
    {
    }
}

Serializer& Serializer::operator=(const Serializer& other) 
{
    if (this != &other) 
    {
    }
    return (*this);
}

Serializer::~Serializer() 
{
}

/*------------------------- Exercise Functions -------------------------*/

Data*    Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}