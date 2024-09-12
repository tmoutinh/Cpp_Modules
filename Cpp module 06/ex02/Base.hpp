/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:42:41 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/09/12 18:42:42 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <sstream>
// # include "A.hpp"
// # include "B.hpp"
// # include "C.hpp"

class Base 
{
    public:
        virtual ~Base();
};

void identify(Base* p);
void identify(Base& p);
Base* generate(void);

#endif