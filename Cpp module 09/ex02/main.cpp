/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:05:57 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/08/29 23:29:54 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    usage()
{
    std::cout << "./PmergeMe [positive integer sequence]" << std::endl;
}

int main(int argc, char *argv[])
{
    std::vector<int>    vec;
    std::deque<int>     deq;
    PmergeMe    sort;
    if (argc < 2)
    {
        usage();
        return (-1);
    }
    if (!sort.parse(argv + 1, vec, deq))
    {
        std::cout << "Error" << std::endl;
        return (-2); 
    }
    double vec_time = sort.mergeInsertSort(vec);
    std::cout << "Time to process a range of " << vec.size() <<" elements with std::Vector : " << vec_time << " s" << std::endl;
    double deq_time = sort.mergeInsertSort(deq);
    std::cout << "Time to process a range of " << vec.size() <<" elements with std::Deque : " << deq_time << " s" << std::endl;
    return (0);
}