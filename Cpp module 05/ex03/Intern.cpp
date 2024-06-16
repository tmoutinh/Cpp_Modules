/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:46:56 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/16 17:52:49 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() 
{
}

Intern::Intern(const Intern& other) 
{
    if (this != &other) 
    {
    }
}

Intern& Intern::operator=(const Intern& other) 
{
    if (this != &other) 
    {
    }
    return (*this);
}

Intern::~Intern() 
{
}

AForm* Intern::makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomy(std::string target) 
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubbery(std::string target) 
{
	return (new ShrubberyCreationForm(target));
}


AForm*    Intern::makeForm(std::string name, std::string target)
{
    typedef AForm* (Intern::*InternFunction)(std::string);
    std::map<std::string, InternFunction> functionMap;
    functionMap["Presidential Form"] = &Intern::makePresidential;
    functionMap["Robotomy Form"] = &Intern::makeRobotomy;
    functionMap["Shrubbery Form"] = &Intern::makeShrubbery;

    try
    {    
        if (functionMap.count(name) > 0) 
            return (this->*functionMap[name])(target);
    }
    catch(const std::exception& e)
    {
        throw Intern::noFormTypeEncountered();
    }
    return (NULL);
}