/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:36:42 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/17 22:51:55 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i)
    {
        vec.push_back(i);
    }
    std::list<int> lst;
    for (int i = 6; i <= 10; ++i)
    {
        lst.push_back(i);
    }
    try
    {
        easyfind(vec, 3);
        easyfind(lst, 11);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}