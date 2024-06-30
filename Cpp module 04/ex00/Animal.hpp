/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:52:55 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:52:56 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &other);
	Animal& operator=(const Animal &other);
    virtual void makeSound() const;
    std::string getType() const;
};

#endif
