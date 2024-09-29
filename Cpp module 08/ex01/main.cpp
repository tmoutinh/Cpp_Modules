/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:59:28 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/17 23:00:06 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
# include <ctime>

int main()
{
    /*--- Normal test ---*/
    std::cout << "/*--- Normal test ---*/" << std::endl;
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    /*--- Full container test ---*/
    std::cout << "\n/*--- Full container test ---*/" << std::endl;
    try
    {
        sp.addNumber(20);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    /*--- Insuficcient number test ---*/
    std::cout << "\n/*--- Insuficcient number test ---*/" << std::endl;
    Span sb = Span(1);
    try
    {
        std::cout << sb.shortestSpan() << std::endl;
        std::cout << sb.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    /*--- Big tester + fill test ---*/
    std::cout << "\n/*--- Big tester + fill test ---*/" << std::endl;
    std::srand(std::time(NULL));
    Span sc = Span(15000);
    try
    {
        sc.fill();
        std::cout << sc.shortestSpan() << std::endl;
        std::cout << sc.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}