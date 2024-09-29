/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:37:07 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/17 22:56:27 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <algorithm>

class NotFound : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Value not found in container.";
    }
};

template <typename T>
void    easyfind(T container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        std::cout << "Value found in container at position " << std::distance (container.begin(), it) << std::endl;
    else
        throw NotFound();
}


    
#endif