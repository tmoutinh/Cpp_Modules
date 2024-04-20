/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:21:09 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/04/20 11:21:10 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Contact.hpp"

Contact::Contact()
{
    return ;
}

Contact::~Contact()
{
    return ;
}

std::string Contact::formatfield(std::string field)
{
    if (field.length() > 10)
        return (field.substr(0,9) + ".");
    return (field);
}

std::string Contact::get_lname()
{
    return (this->_lname);
}

std::string Contact::get_fname()
{
    return (this->_fname);
}

std::string Contact::get_nick()
{
    return (this->_nick);
}

Contact::Contact(std::string fn, std::string ln, std::string nc, std::string nb, std::string se)
{
    this->_fname = fn;
    this->_lname = ln;
    this->_nick = nc;
    this->_numb = nb;
    this->_secret = se;
    return ;
}

void    Contact::display()
{
    std::cout << "First Name: " << this->_fname << std::endl;
    std::cout << "Last Name: " << this->_lname << std::endl;
	std::cout << "Nickname: " << this->_nick << std::endl;
    std::cout << "Phone Number: " << this->_numb << std::endl;
    std::cout << "Darkest Secret: " << this->_secret << std::endl;
    std::cout << std::endl;
}
