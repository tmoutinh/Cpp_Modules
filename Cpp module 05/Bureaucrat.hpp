
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

    int getGrade();
    std::string getName();
    void    decreaseGrade();
    void    incrementGrade();
};





#endif