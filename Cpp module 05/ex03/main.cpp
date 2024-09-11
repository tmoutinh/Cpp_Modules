/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:11:19 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/16 18:12:20 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	
    {
        AForm   *test1;
        AForm   *test2;
        AForm   *test3;
        Intern  someRandomIntern;
        Bureaucrat someRandomBureaucrat("Bender", 1);
        
        try
        {
            test1 = someRandomIntern.makeForm("Presidential Form", "Bender");
            someRandomBureaucrat.signForm(*test1);
            someRandomBureaucrat.executeForm(*test1);
            test2 = someRandomIntern.makeForm("Robotomy Form", "Bender");
            someRandomBureaucrat.signForm(*test2);
            someRandomBureaucrat.executeForm(*test2);
            test3 = someRandomIntern.makeForm("Shrubbery Form", "Bender");
            someRandomBureaucrat.signForm(*test3);
            someRandomBureaucrat.executeForm(*test3);
            delete test1;
            delete test2;
            delete test3;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Excepetion caught: " << e.what() <<  '\n';
        }
    }
	return (0);
}
