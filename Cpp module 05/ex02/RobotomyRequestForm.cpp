/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:18:06 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/15 18:33:36 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):AForm(other)
{
    if (this != &other) 
    {
        this->_target = other._target;
    }
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other) 
        this->_target = other._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() == false)
        throw AForm::NotSigned();
    if (this->getGradeToExec() < executor.getGrade())
        throw AForm::GradeTooLowException();
    std::cout << "*drilling noises* ";
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->_target << " robotomization failed" << std::endl;
}
