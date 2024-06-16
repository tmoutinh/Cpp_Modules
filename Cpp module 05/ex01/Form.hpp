/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:54:53 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/15 15:57:59 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FORM_HPP
# define _FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;	
class Form 
{
    private:
        const std::string   name;
        bool                sign;
        int           gradeToSign;
        int           gradeToExec;
    public:
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        std::string getName() const;
        bool        getSign() const;
        int         getGradeToSign() const;
        int         getGradeToExec() const;
        void        beSigned(Bureaucrat &b);
    	/*-------  Exception classes  -------*/
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw() {return "Grade too high exception: grade < 1";}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw() {return "Grade too low exception: grade > 150";}
	};
};

std::ostream&	operator<< (std::ostream& os, Form const &b);

#endif
