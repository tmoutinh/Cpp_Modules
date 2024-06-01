/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:47:25 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:47:26 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
    int fnumber;
    static const int frac = 8;
public:
    /*************-- Ex00 --***************/
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    int     getRawBits() const;
    void    setRawBits (int const raw);
    /*************-- Ex01 --***************/
    Fixed(int number);
    Fixed(float numberf);
    float   toFloat(void) const;
    int     toInt (void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& num);

#endif
