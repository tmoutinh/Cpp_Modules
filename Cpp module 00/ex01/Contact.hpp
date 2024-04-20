/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:21:02 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/04/20 11:21:03 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <stdlib.h>
# include <unistd.h>
# include <sstream>

/*************** -ContactClass- *********************/

class Contact
{
public:
    Contact();
    ~Contact();
    Contact(std::string fn, std::string ln, std::string nc, std::string nb, std::string se);
    
    void    display();
    std::string get_fname();
    std::string get_lname();
    std::string get_nick();
    static std::string formatfield(std::string);

private:    
    std::string _fname;
    std::string _lname;
    std::string _nick;
    std::string _numb;
    std::string _secret;
};

#endif
