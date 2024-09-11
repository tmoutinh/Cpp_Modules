/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:43:55 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/16 17:27:35 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>
#include <map>


class Intern 
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
        
        AForm*    makeForm(std::string name, std::string target);
        AForm	*makePresidential(std::string target);
		AForm	*makeRobotomy(std::string target);
		AForm	*makeShrubbery(std::string target);
        class noFormTypeEncountered : public std::exception
	    {
	    	public:
		    	virtual const char *what() const throw() { return ("No Form type was encountered with the provided name.");}
	    };
};




#endif
