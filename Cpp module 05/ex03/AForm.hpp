/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:54:53 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/16 18:09:29 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AFORM_HPP
# define _AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;	
class AForm 
{
    private:
        const std::string   name;
        bool                sign;
        int           gradeToSign;
        int           gradeToExec;
    public:
        AForm(std::string name, int gradeToSign, int gradeToExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        std::string getName() const;
        bool        getSign() const;
        int         getGradeToSign() const;
        int         getGradeToExec() const;
        void        beSigned(Bureaucrat &b);
        virtual     void execute(Bureaucrat const & executor) const = 0;
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
    class NotSigned : public std::exception
	{
		public:
			virtual const char *what() const throw() {return "Can't execute: Not Signed";}
	};
};

std::ostream&	operator<< (std::ostream& os, AForm const &b);

#endif
