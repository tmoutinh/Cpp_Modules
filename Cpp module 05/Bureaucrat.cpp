#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) 
{
    this->name = name;
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
    if (this != &other) 
    {
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() 
{
}

int Bureaucrat::getGrade()
{

}

std::string Bureaucrat::getName()
{

}

void    Bureaucrat::decreaseGrade()
{

}

void    Bureaucrat::incrementGrade()
{

}

