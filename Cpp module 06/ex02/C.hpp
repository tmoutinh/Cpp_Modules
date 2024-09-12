/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:42:31 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/09/12 18:42:31 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef C_HPP
# define C_HPP

# include "Base.hpp"

class C : public Base
{
    public:
        ~C();
        C();
        C(const C& other);
        C& operator=(const C& other);
};


#endif