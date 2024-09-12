/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:42:19 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/09/12 18:42:20 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"

void testBadIdentify(void)
{
	std::cout << "\n\t======== Testing bad identify ========\n\n";
	
	Base *pointer = NULL;
	Base reference;
	
	identify(pointer);
	identify(reference);
}

void testGoodIdentify(void)
{
	std::cout << "\n\t======== Testing good identify ========\n\n";

	Base *random;
	random = generate();

	identify(random);
	identify(*random);
	delete random;
}

int main()
{
	std::srand(time(NULL));
	testGoodIdentify();
	testBadIdentify();
	return (0);
}