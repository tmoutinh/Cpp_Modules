/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:12:33 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/27 16:12:46 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#   include <stdio.h>
#   include <vector>
#   include <iostream>
#   include <sstream> 
#   include <algorithm>

class PmergeMe 
{
    private:
        std::vector<int>    _a_side;
        std::vector<int>    _b_side;
        std::vector<int>    _result;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        bool    parse(char* argv[]);
        void    pair_split();
};

#endif