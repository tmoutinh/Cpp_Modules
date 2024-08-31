/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:12:33 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/08/29 23:22:12 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#   include <stdio.h>
#   include <vector>
#   include <iostream>
#   include <sstream> 
#   include <algorithm>
#   include <cmath>
//#   include <chrono>
#   include <deque>
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX(a, b) ((a) > (b) ? (a) : (b))

class PmergeMe 
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        bool    parse(char *argv[], std::vector<int> &vec, std::deque<int> &deq);
        /*--------------- Vec Functions ----------------------------------*/
        void    generateJacobsthalSequence(std::vector<size_t> &vec, size_t size);
        double  mergeInsertSort(std::vector<int> &nums);
        void    sorting(std::vector<std::vector<int> > &pairs);
        void    sorter(std::vector<std::vector<int> > &pairs, std::vector<std::vector<int> > left, std::vector<std::vector<int> > right);
        void    pair_split(std::vector<int> &nums, std::vector<std::vector<int> > &pairs);
        void    merging(std::vector<int> &result, std::vector<std::vector<int> > &pairs);
        void    place(std::vector<int> &result, int number);
        void    print(std::vector<int> &result, std::string type);

        /*--------------- Deq Functions ----------------------------------*/
        void    generateJacobsthalSequence(std::deque<size_t> &vec, size_t size);
        double  mergeInsertSort(std::deque<int> &nums);
        void    sorting(std::deque<std::deque<int> > &pairs);
        void    sorter(std::deque<std::deque<int> > &pairs, std::deque<std::deque<int> > left, std::deque<std::deque<int> > right);
        void    pair_split(std::deque<int> &nums, std::deque<std::deque<int> > &pairs);
        void    merging(std::deque<int> &result, std::deque<std::deque<int> > &pairs);
        void    place(std::deque<int> &result, int number);
        void    print(std::deque<int> &result, std::string type);
};

#endif