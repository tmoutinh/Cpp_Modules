/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:54:01 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:54:02 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP

#define BRAIN_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    ~Brain();
    Brain(const Brain &other);
	Brain& operator=(const Brain &other);
};


#endif
