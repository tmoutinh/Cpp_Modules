/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:55:34 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/01 14:55:35 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include "Cat.hpp"
#include "Dog.hpp"

void test_animal_copies(void)
{
	std::cout << "\n\t=== Testing shallow/deep copies ===\n" << std::endl;
	
	Cat *cat = new Cat();
	Cat *clone = new Cat(*cat);

	std::cout << "\n\tCats brain: " << cat->getBrain() << std::endl << std::endl;
	delete cat;

	std::cout << "\tClone cat brain: " << clone->getBrain() << std::endl << std::endl;
	delete clone;

	std::cout << std::endl;
}

void test_destructors(void)
{
	std::cout << "\n\t=== Testing destructors ===\n" << std::endl;
	
	Animal *animals[4] = 
	{
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat()
	};

	for (int i = 0; i < 4; i++)
		delete animals[i];
}

void test_inheritance(void)
{
	std::cout << "\n\t=== Testing new animals growls ===\n" << std::endl;
	
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
}

int main()
{
	test_animal_copies();
	test_inheritance();
	test_destructors();	
}