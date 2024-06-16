
#ifndef _BUREAUCRAT_HPP
# define _BUREAUCRAT_HPP

#include <iostream>


class Bureaucrat
{
private:
	std::string	name;
	int	grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);

    int getGrade() const;
    std::string getName() const;
    void    decreaseGrade();
    void    incrementGrade();

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

std::ostream&	operator<< (std::ostream& os, Bureaucrat const &b);




#endif