/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:11:57 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/16 16:32:15 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) 
{
    if (this != &other) 
    {
        this->sign = other.sign;
        this->gradeToSign = other.gradeToSign;
        this->gradeToExec = other.gradeToExec;
    }
}

AForm& AForm::operator=(const AForm& other) 
{
    if (this != &other) 
    {
        this->sign = other.sign;
        this->gradeToSign = other.gradeToSign;
        this->gradeToExec = other.gradeToExec;
    }
    return (*this);
}

AForm::~AForm() 
{
}

bool AForm::getSign() const
{
    return (this->sign);
}

int AForm::getGradeToExec() const
{
    return (this->gradeToExec);
}

int AForm::getGradeToSign() const
{
    return (this->gradeToSign);
}

std::string AForm::getName() const
{
    return (this->name);
}

void    AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    this->sign = true;
}

std::ostream&   operator<< (std::ostream& os, const AForm& b)
{
    os << b.getName() << " AForm is signed ? " << b.getSign() << std::endl \
    << "Grade to sign: " << b.getGradeToSign() << std::endl \
    << "Grade to exec: " << b.getGradeToExec() << std::endl;
    return (os);
}
