/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:36:00 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/15 18:33:42 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other)
{
    if (this != &other) 
    {
        this->_target = other._target;
    }
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other) 
        this->_target = other._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() == false)
        throw AForm::NotSigned();
    if (this->getGradeToExec() < executor.getGrade())
        throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
