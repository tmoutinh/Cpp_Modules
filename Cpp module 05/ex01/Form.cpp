/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:11:57 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/16 16:36:53 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExec) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) 
{
    if (this != &other) 
    {
        this->sign = other.sign;
        this->gradeToSign = other.gradeToSign;
        this->gradeToExec = other.gradeToExec;
    }
}

Form& Form::operator=(const Form& other) 
{
    if (this != &other) 
    {
        this->sign = other.sign;
        this->gradeToSign = other.gradeToSign;
        this->gradeToExec = other.gradeToExec;
    }
    return (*this);
}

Form::~Form() 
{
}

bool Form::getSign() const
{
    return (this->sign);
}

int Form::getGradeToExec() const
{
    return (this->gradeToExec);
}

int Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

std::string Form::getName() const
{
    return (this->name);
}

void    Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    this->sign = true;
}

std::ostream&   operator<< (std::ostream& os, const Form& b)
{
    os << b.getName() << " form is signed ? " << b.getSign() << std::endl \
    << "Grade to sign: " << b.getGradeToSign() << std::endl \
    << "Grade to exec: " << b.getGradeToExec() << std::endl;
    return (os);
}
